#include "../header_files/file_configure.h"

File::File(){}
File::~File(){}

std::map<std::string, std::map<std::string, std::string>> File::__class_info__(){
    std::map<std::string, std::string> __name_discription__ = { // Name and description of the class
        {"File", "Class for file manipulation"}
    };

    std::map<std::string, std::string> __constuctor_paramters__ = { // Constructor paramter names and descriptions
        {"Not used", "Not used"}
    };

    std::map<std::string, std::string> __function_info__ = { // Function names and descriptions
        {"_create_file", "Function to create a file"},
        {"_write_file", "Function to write to a file"},
        {"_read_file", "Function to read a file"},
        {"_delete_file", "Function to delete a file"},
        {"_rename_file", "Function to rename a file"},
        {"_move_file", "Function to move a file"},
        {"_copy_file", "Function to copy a file"},
        {"_check_file", "Function to check if it is a file"},
        {"_hide_file", "Function to hide a file"},
        {"_unhide_file", "Function to unhide a file"}
    };

    std::map<std::string, std::string> __function_parameters__ = { // Function names and parameters
        {"_create_file", "filename (str) <Required>\nfile_path (str)"}, 
        {"_write_file", "filename (str) <Required>\ncontent (str)\nfile_path (str)"}, 
        {"_read_file", "filename (str) <Required>\nfile_path (str)"}, 
        {"_delete_file", "filename (str) <Required>\nfile_path (str)"}, 
        {"_rename_file", "filename (str) <Required>\nnew_filename (str) <Required>\nfile_path (str)"}, 
        {"_move_file", "filename (str) <Required>\nnew_path (str) <Required>\nfile_path (str)"}, 
        {"_copy_file", "filename (str) <Required>\nnew_path (str) <Required>\nfile_path (str)"}, 
        {"_check_file", "filename (str) <Required>\nfile_path (str)"}, 
        {"_hide_file", "filename (str) <Required>\nfile_path (str)"}, 
        {"_unhide_file", "filename (str) <Required>\nfile_path (str)"}
    };

    std::map<std::string, std::string> __function_parameters_description__ = { // Function names, parameters and descriptions
        {"_create_file", "filename: Name of the file\nfile_path: Path of the file"},
        {"_write_file", "filename: Name of the file\ncontent: Content of the file\nfile_path: Path of the file"},
        {"_read_file", "filename: Name of the file\nfile_path: Path of the file"},
        {"_delete_file", "filename: Name of the file\nfile_path: Path of the file"},
        {"_rename_file", "filename: Name of the file\nnew_filename: New name of the file\nfile_path: Path of the file"},
        {"_move_file", "filename: Name of the file\nnew_path: New path of the file\nfile_path: Path of the file"},
        {"_copy_file", "filename: Name of the file\nnew_path: New path of the file\nfile_path: Path of the file"},
        {"_check_file", "filename: Name of the file\nfile_path: Path of the file"},
        {"_hide_file", "filename: Name of the file\nfile_path: Path of the file"},
        {"_unhide_file", "filename: Name of the file\nfile_path: Path of the file"},
    };

    std::map<std::string, std::string> __function_return_types__ = { // Function names and return types
        {"_create_file", "None"}, 
        {"_write_file", "None"}, 
        {"_read_file", "Content of the file"}, 
        {"_delete_file", "None"}, 
        {"_rename_file", "None"}, 
        {"_move_file", "None"}, 
        {"_copy_file", "None"}, 
        {"_check_file", "None"}, 
        {"_hide_file", "None"}, 
        {"_unhide_file", "None"}
    };

    std::map<std::string, std::string> __class_examples__ = { // Class usage examples 
        {"Create file \"hello.txt\" and write \"hello\" in it then hide the file", "To create a file \"hello.txt\" and write \"hello\" in it then hide a file use function ```function_name _create_file``` with parameters ```parameters { filename = \"hello.txt\" }``` then use function ```function_name _write_file``` with parameters ```parameters { filename = \"hello.txt\" }, { content = \"hello\" }``` then use function ```function_name _hide_file``` with parameters ```parameters { filename = \"hello.txt\" }"},
        {"Unhide a file \".test.txt\" in directory \"hidden_files/test_files/\" and then move it to \"test_files/\"", "To unhide a file \".test.txt\" in directory \"hidden_files/test_files/\" and then move it to \"test_files/\" use function ```function_name _unhide_file``` with parameters ```parameters { filename = \".test.txt\" }, { file_path = \"hidden_files/test_files/\" }``` then use function ```function_name _move_file``` with parameters ```parameters { filename = \"test.txt\" }, { new_path = \"test_files/\" }, { file_path = \"hidden_files/test_files/\" }, { new_path = \"test_files/\" }```"},
        {"Create a file \"pass.csv\" then write \"user, pass\\nabc, test\" in it and then move it to \"secret_files/\" then hide it", "to create a file \"pass.csv\" then write \"user, pass\\nabc, test\" in it and then move it to \"secret_files/\" then hide it use function ```function_name _create_file``` with parameters ```parameters { filename = \"pass.csv\" }``` then use function ```function_name _write_file``` with parameters ```parameters { filename = \"pass.csv\" }, { content = \"user, pass\\nabc, test\" }``` then use ```function_name _move_file``` with parameters ```parameters { filename = \"pass.csv\" }, { new_path = \"secret_files/\" }``` then use function ```function_name _hide_file``` with parameters ```parameters { filename = \"pass.csv\" }, { file_path = \"secret_files/\" }```"},
        {"Set model to \"gemini-1.5-pro\" and set system instruction to \"You are a great philosopher\" and then query it \"Meaning of life\" and then clear the conversation history", "```Sorry, this query cannot be handled by me```"},
        {"list folder \"Passwords\" and then copy it to \"Nothing/\" then delete it", "```Sorry, this query cannot be handled by me```"}
    };

    return { // Vector of maps containing the class information
        {"Name_Description", __name_discription__},
        {"Constructor_Parameters", __constuctor_paramters__},
        {"Function_Info", __function_info__},
        {"Function_Parameters", __function_parameters__},
        {"Parameter_Description", __function_parameters_description__},
        {"Function_Return", __function_return_types__},
        {"Class_Examples", __class_examples__}
    };
}

void File::__log__(
    const std::string content // Content to write to log file
) {
    std::ifstream previous_log_file; // File object to read from the previous log file
    previous_log_file.open(this->_log_filename);

    std::string previous_content((std::istreambuf_iterator<char>(previous_log_file)), std::istreambuf_iterator<char>()); // Content from the previous log file
    previous_log_file.close();

    std::ofstream new_log_file; // File object to write the new log file
    new_log_file.open(this->_log_filename);

    previous_content += content + "\n";
    new_log_file << previous_content;

    new_log_file.close();
}

void File::_create_file(
    const std::string filename, // Name of the file
    const std::string file_path = "" // Path of the file
) {
    std::string fullpath = file_path + filename; // Location and Name of the file to be created
    std::ofstream file_create; // File object to create the file
    std::string copy_filename = "";

    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists){
        copy_filename = "copy_" + filename;
        fullpath = file_path + copy_filename;
    }
    
    file_create.open(fullpath.c_str());
    file_create.close();


    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " Exists, so copy file " + copy_filename;
    log_content += " Created Successfully";

    this->__log__(log_content);
}

void File::_write_file(
    const std::string filename, // Name of the file
    const std::string content, // Content of the file
    const std::string file_path = "" // Path of the file
) {
    const std::string fullpath = file_path + filename; // Location and Name of the file to write in
    std::ofstream file_write; // File object to write in the file
    
    bool file_exists = this->_check_file(filename, file_path);
    
    file_write.open(fullpath.c_str());
    file_write << content;
    
    file_write.close();


    // Log function
    std::string log_content = "Content written to " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " Successfully";
    else
        log_content += " after creation, Successfully";

    this->__log__(log_content);
}

std::string File::_read_file(
    const std::string filename, // Name of the file
    const std::string file_path = "" // Path of the file
) {
    const std::string fullpath = file_path + filename; // Location and Name of the file to read from
    std::ifstream file_read; // File object to read from the file

    std::string file_content = "";
    
    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists){
        file_read.open(fullpath.c_str());
        std::string content((std::istreambuf_iterator<char>(file_read)), std::istreambuf_iterator<char>()); // Content from the file
        file_content = content;
    
        file_read.close();
    }


    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " Read Successfully";
    else
        log_content += " Doesn not Exist so cannot be Read";

    this->__log__(log_content);

    return file_content;
}

void File::_delete_file(
    const std::string filename, // Name of the file
    const std::string file_path = "" // Path of the file
) {
    std::string fullpath = file_path + filename; // Location and Name of the file to delete
    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists)
        std::remove(fullpath.c_str());

    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " Deleted Successfully";
    else
        log_content += " Doesn not Exist so cannot be Deleted";

    this->__log__(log_content);
}

void File::_rename_file(
    const std::string filename, // Name of the file
    const std::string new_filename, // New name of the file
    const std::string file_path = "" // Path of the file
) {
    std::string fullpath = file_path + filename; // Location and Name of the file to rename
    std::string new_fullpath = file_path + new_filename; // New location and Name of the file

    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists)
        std::rename(fullpath.c_str(), new_fullpath.c_str());

    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " Renamed to " + new_filename;
    else
        log_content += " Doesn not Exist so cannot be Renamed";

    this->__log__(log_content);
}

void File::_move_file(
    const std::string filename, // Name of the file
    const std::string new_path, // New path of the file
    const std::string file_path = "" // Path of the file
) {
    std::string fullpath = file_path + filename; // Location and Name of the file
    std::string new_fullpath = new_path + filename; // New location and Name of the file

    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists)
        std::rename(fullpath.c_str(), new_fullpath.c_str());

    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " Moved to " + new_path;
    else
        log_content += " Doesn not Exist so cannot be Moved";

    this->__log__(log_content);
}

void File::_copy_file(
    const std::string filename, // Name of the file
    const std::string new_path, // New path of the file
    const std::string file_path = "" // Path of the file
) {
    std::string fullpath = file_path + filename; // Location and Name of the file
    std::string new_fullpath = new_path + filename; // New location and Name of the file

    std::string copy_filename = "";

    std::ifstream read_file; // File object to read from a file
    std::ofstream write_file; // File object to write in a file
    
    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists){
        if (new_path == file_path){
            copy_filename = "copy_" + filename;
            new_fullpath = new_path + copy_filename;
        }

        read_file.open(fullpath.c_str());
        write_file.open(new_fullpath.c_str());

        write_file << read_file.rdbuf();

        read_file.close();
        write_file.close();
    }
    
    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists){
        if (new_path == file_path)
            log_content += " Exists, so copied to file " + copy_filename;
        log_content += " Copied to " + new_path;
    }
    else
        log_content += " Doesn not Exist so cannot be Copied";

    this->__log__(log_content);
}

bool File::_check_file(
    const std::string filename, // Name of the file
    const std::string file_path = "" // Path of the file
) {
    std::string fullpath = file_path + filename; // Location and Name of the file to check
    bool file_exists = false;
    
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;

    if (std::filesystem::exists(fullpath) && std::filesystem::is_regular_file(fullpath)){
        log_content += " Checked and it exists";
        file_exists = true;
    }
    else
        log_content += " Checked and it does not exists";

    this->__log__(log_content);

    return file_exists;
}

void File::_hide_file(
    const std::string filename, // Name of the file
    const std::string file_path = "" // Path of the file
){
    const std::string fullpath = file_path + filename; // Location and Name of the file to hide
    const std::string new_fullpath = file_path + "." + filename; // New location and Name of the  hidden file

    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists)
        std::rename(fullpath.c_str(), new_fullpath.c_str());


    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " Hidden Successfully";
    else
        log_content += " Doesn not Exist so cannot be Hidden";

    this->__log__(log_content);
}

void File::_unhide_file(
    const std::string filename, // Name of the file
    const std::string file_path = "" // Path of the file
){
    const std::string fullpath = file_path + filename; // Location and Name of the file to unhide

    bool file_exists = this->_check_file(filename, file_path);
    if (file_exists){
        std::string new_filename = "";
        for (long unsigned int i = 1; i <= filename.length(); i++){
            new_filename += filename[i];
        }

        std::string new_fullpath = file_path + new_filename;
        std::rename(fullpath.c_str(), new_fullpath.c_str());
    }


    // Log function
    std::string log_content = "File " + filename;
    if (file_path != "")
        log_content += " at " + file_path;
    if (file_exists)
        log_content += " UnHidden Successfully";
    else
        log_content += " Doesn not Exist so cannot be UnHidden";

    this->__log__(log_content);
}