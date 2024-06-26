#ifndef BROWSERS_H
#define BROWSERS_H 

std::vector<std::vector<std::string>> getBrowsers() {
  std::vector<std::vector<std::string>> browsers {
    {"brave", "Brave.Brave"},
    {"chrome", "Google.Chrome.EXE"},
    {"firefox", "Mozilla.Firefox"},
    // {"chromium-browser", "Hibbiki.Chromium"} same command as chrome when opening websites
    {"msedge", "Microsoft.Edge"},
    {"opera", "Opera.Opera"}
  };
  return browsers;
}

void openWebsites(std::string browser) {
  std::string websites[] =  { "google.com", "blogger.com", "youtube.com", "linkedin.com",
  "wordpress.org", "apple.com", "wikipedia.org", "whatsapp.com", "telegram.org", "mozilla.org",
  "facebook.com", "adobe.com", "github.com", "amazon.com", "imdb.com", "paypal.com" 
  };
  
  for (int i = 0; i < size(websites); i++) {
    std::string command = "start " + browser + " " + websites[i];
    system(command.c_str());
  }
}

std::string getBrowserID(std::string browser) {
  std::vector<std::vector<std::string>> browsers = getBrowsers();
  std::string output = "";
  for(int i = 0; i < size(browsers); i++) {
    if (browsers[i][0] == browser) {
      output = browsers[i][1];
    }
  }
  return output;
}

void installBrowser(std::string browser) {
  std::string command = "winget install --id " + getBrowserID(browser) + " --silent";
  system(command.c_str());
  openWebsites(browser);
}

#endif

