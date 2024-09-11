import os
import json
import google.generativeai as genai

from typing import Any, Iterable, Mapping
from google.generativeai.types import HarmCategory, HarmBlockThreshold

class GeminiModel():
    def __init__(self) -> None:
        """
            Args:
                None
            
            Returns:
                None
            
            Summary:
                Initializes the GeminiModel class.
        """
        
        self._model_name = "gemini-1.5-pro"
        self._context = "you are a helpful assistant"
        
        self._history = [{
            "Role": "SYSTEM:",
            "Content": self._context
        }]
        
        self._safety_settings = { # Default settings for gemini model
            HarmCategory.HARM_CATEGORY_DANGEROUS_CONTENT: HarmBlockThreshold.HARM_BLOCK_THRESHOLD_UNSPECIFIED,
            HarmCategory.HARM_CATEGORY_HARASSMENT: HarmBlockThreshold.HARM_BLOCK_THRESHOLD_UNSPECIFIED,
            HarmCategory.HARM_CATEGORY_HATE_SPEECH: HarmBlockThreshold.BLOCK_LOW_AND_ABOVE,
            HarmCategory.HARM_CATEGORY_SEXUALLY_EXPLICIT: HarmBlockThreshold.BLOCK_LOW_AND_ABOVE,
        }
        
        self._configure_model()
        
        self._configuration = genai.GenerationConfig()
        self._model = genai.GenerativeModel(self._model_name, generation_config=self._configuration, system_instruction=self._context, safety_settings=self._safety_settings)
    
    def query_model(self, query: str, verbose: False) -> str:
        """
            Args:
                query: The prompt you wish to ask gemini
                verbose: Whether to print the responce in verbose mode
            
            Returns:
                String of responce given by gemini
            
            Summary:
                Asks the gemini model the given prompt with the previous history and returns the responce.
        """
        
        history = self._get_previous_messages()
        responce = self._model.generate_content(history + "\n\nUser:" + query)
        
        self._history.append({
            "Role": "USER:",
            "Content": query
        })
        self._history.append({
            "Role": "ASSISTANT:",
            "Content": responce.text
        })
        self._save_history()
        
        return responce._result if verbose else responce.text
    
    def get_available_models(self) -> list:
        """
            Args:
                None
            
            Returns
                List of model names
            
            Summary:
                Returns a list of model names available with the current api
        """
        
        return [model.name for model in genai.list_models()]
    
    def modify_safety_settings(self, safety: HarmCategory.name, setting: HarmBlockThreshold.name = HarmBlockThreshold.BLOCK_LOW_AND_ABOVE) -> None:
        """
            Args:
                safety: Safety Category to change
                setting: Content level to block for the category
            
            Returns:
                None
            
            Summary:
                Changes the safety settings for the content generated by the model
        """
        
        self._safety_settings[safety] = setting
        self._model._safety_settings = self._safety_settings
    
    def get_current_configuration(self) -> object:
        """
            Args:
                None
            
            Returns:
                None
            
            Summary:
                Returns the current configuration of the model.
        """
        
        return self._configuration
    
    def set_configuration(
        self,
        candidate_count: int | None = None,
        stop_sequences: Iterable[str] | None = None,
        max_output_tokens: int | None = None,
        temperature: float | None = None,
        top_p: float | None = None,
        top_k: int | None = None,
        response_mime_type: str | None = None,
        response_schema: Mapping[str, Any] | None = None) -> None:
        """
            Args:
                candidate_count: The number of candidate
                stop_sequences: List of string to stop the generation at
                max_output_tokens: How many token's output must gemini model give
                temperature: Controls the randomness of the output.
                top_p: The maximum cumulative probability of tokens to consider when sampling.
                top_k: The maximum number of tokens to consider when sampling.
                response_mime_type: Output response mimetype of the generated candidate text.
                response_schema: Specifies the format of the JSON requested if response_mime_type is application/json.
            
            Returns:
                None
            
            Summary:
                Sets the configuration of the model.
        """
        
        self._configuration.candidate_count = candidate_count
        self._configuration.stop_sequences = stop_sequences
        self._configuration.max_output_tokens = max_output_tokens
        self._configuration.temperature = temperature
        self._configuration.top_p = top_p
        self._configuration.top_k = top_k
        self._configuration.response_mime_type = response_mime_type
        self._configuration.response_schema = response_schema
        
        self._model._generation_config = self._configuration
    
    def get_model(self) -> genai.GenerativeModel:
        """
            Args:
                None
            
            Returns:
                None
            
            Summary:
                Returns the current model being used.
        """
        
        return self._model

    def set_model(self, model_name: str, system_message: str | None = None, safety_settings: Mapping[HarmCategory: HarmBlockThreshold] | None = None) -> None:
        """
            Args:
                model_name: Name of the model you want to use
                system_message: System message for the model

            Returns:
                None
            
            Summary:
                Sets the new model name and system message if given
        """
        
        self._model.model_name = model_name
        self._model._system_instruction = self._context if system_message is not None else system_message
        self._model._safety_settings = safety_settings if safety_settings is not None else self._safety_settings
    
    def load_history(self, filename: str= "json_files/gemini_history.json") -> list:
        """
            Args:
                filename: Name of the file to load the history from
            
            Returns:
                None
            
            Summary:
                Loads the history from the given file
        """
        
        with open(filename, 'r', encoding='utf-8') as file:
            history = json.load(file)
        
        return history
    
    def clear_history(self, filename: str="json_files/gemini_history.json") -> None:
        """
            Args:
                filename: Name of the file to clear the history from
            
            Returns:
                None
            
            Summary:
                Clears the history from the given file
        """
        
        with open(filename, 'w', encoding='utf-8') as file:
            json.dump([{"Role": "SYSTEM:", "Content": self._context}], file, ensure_ascii=False, indent=4)
        
        self._history = [{"Role": "SYSTEM:", "Content": self._context}]

    def _get_previous_messages(self) -> str:
        """
            Args:
                None
            
            Returns:
                String of the previous messages by USER and ASSISTANT
            
            Summary:
                Returns the previous messages by USER and ASSISTANT
        """
        
        history = ""
        
        for message in self._history:
            history += f"{message['Role']}: {message['Content']}\n"
        
        return history

    def _save_history(self, filename: str="json_files/gemini_history.json") -> None:
        """
            Args:
                filename: Name of the file to save the history to
            
            Returns:
                None
            
            Summary:
                Saves the history to the given file
        """
        
        with open(filename, 'w', encoding='utf-8') as file:
            json.dump(self._history, file, ensure_ascii=False, indent=4)

    def _configure_model(self) -> None:
        """
            Args:
                None
            
            Returns:
                None
            
            Summary:
                Configures the model with the given configuration
        """
        
        from dotenv import load_dotenv
        load_dotenv("secret_files/.env")
        
        genai.configure(api_key=os.getenv("GEMINI_API_KEY"))
