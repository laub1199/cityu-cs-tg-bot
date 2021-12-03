import pickle
import bs4
import urllib.request as req
import re

crypto_dict = {}
for page in range(1, 115):
    url="https://www.coingecko.com/en"
    if page >= 1:
        url += '?page={}'.format(str(page))
    request = req.Request(url, headers={
        "User-Agent": 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36'
    })
    with req.urlopen(request) as res:
        data=res.read().decode("utf-8")
    root=bs4.BeautifulSoup(data, 'html.parser')
    trs = root.find_all('tr')
    index = 0
    for tr in trs:
        symbol= ''
        idx = ''
        for td in tr.find_all('td', class_='coin-name'):
            for a in td.find_all('a', class_='d-lg-none font-bold'):
                symbol = re.findall(r'(?<=\n).+?(?=\n)', a.get_text())[0]
        for td in tr.find_all('td', class_='p-0 pl-2 text-center'):
            for a in td.find_all('a'):
                for img in a.find_all('img'):
                    idx = re.findall(r'(?<=/coins/).+?(?=/sparkline)', img['data-src'])[0]
        if symbol != '' and idx != '':
            crypto_dict[symbol] = idx
    print('Finish processing {}'.format(page))
with open('pickles/crypto_dict.pickle', 'wb') as f:
    pickle.dump(crypto_dict, f)
#
# msft = yf.Ticker("nvda")
#
# print(msft.info['currentPrice'])
# print(msft.info['dayHigh'])
# print(msft.info['dayLow'])
# print(msft.info['targetLowPrice'])
# print(msft.info['targetMeanPrice'])
# print(msft.info['targetHighPrice'])
# print(msft.info['preMarketPrice'])
# print(msft.info['volume'])
# print(msft.info['marketCap'])
# print(msft.info['regularMarketPreviousClose'])