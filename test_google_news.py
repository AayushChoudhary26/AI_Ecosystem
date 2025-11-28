from modules.angel_configure import GoogleNews

google_news = GoogleNews()
google_news._get_news("Bynry", "results.txt")

from modules.angel_configure import GoogleSearch

google_search = GoogleSearch()
google_search._search_google("Bynry Smart360", "search_results.json")