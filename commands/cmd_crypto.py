from pycoingecko import CoinGeckoAPI
from math import log10, floor

def round_sig(x, sig=2):
    return round(x, sig - int(floor(log10(abs(x)))) - 1)

def check_precision(p):
    start_count = False
    count = 0
    for idx in str(p):
        if start_count:
            count += 1
        elif idx == '.':
            start_count = True
    return str(count)

def price_string(p):
    p = p if p >= 100 else round_sig(p, 3)
    return ('${:,.' + check_precision(p) + 'f}').format(p)

def crypto(update, context):
    if not context.args:
        update.message.reply_text("Symbol is missing, e.g. /crypto btc")
    elif len(context.args) > 1:
        update.message.reply_text("Only 1 symbol is required, e.g. /crypto btc")
    else:
        cg = CoinGeckoAPI()
        crypto_list = cg.get_coins_list()
        text = ''
        for crypto in crypto_list:
            if crypto['symbol'] == context.args[0].lower():
                target_usd = cg.get_coins_markets(ids=crypto['id'], vs_currency='usd', price_change_percentage='1h,24h,7d')[ 0]
                target_hkd = cg.get_coins_markets(ids=crypto['id'], vs_currency='hkd', price_change_percentage='1h,24h,7d')[ 0]

                text += '{} - ${} [{}]\n'.format(target_usd['name'], target_usd['symbol'].upper(), target_usd['market_cap_rank'])
                text += '💰 Price [USD]: {}\n'.format(price_string(target_usd['current_price']))
                text += '⚖ H: {} | L: {}\n'.format(price_string(target_usd['high_24h']), price_string(target_usd['low_24h']))
                text += '🇭🇰 Price [HKD]: {}\n'.format(price_string(target_hkd['current_price']))
                text += '📈 ' if target_usd['price_change_percentage_1h_in_currency'] > 0 else '📉 '
                text += '1h: {:,.2f}%\n'.format(target_usd['price_change_percentage_1h_in_currency'])
                text += '📈 ' if target_usd['price_change_percentage_24h_in_currency'] > 0 else '📉 '
                text += '24h: {:,.2f}%\n'.format(target_usd['price_change_percentage_24h_in_currency'])
                text += '📈 ' if target_usd['price_change_percentage_7d_in_currency'] > 0 else '📉 '
                text += '7d: {:,.2f}%\n'.format(target_usd['price_change_percentage_7d_in_currency'])
                text += '📊 Volume: ${:,.0f}\n'.format(target_usd['total_volume'])
                text += '💎 MarketCap: ${:,.0f}\n'.format(target_usd['market_cap'])
                break

        if text == '':
            text = "Couldn't find your Shitcoin!"

        update.message.reply_text(text)
