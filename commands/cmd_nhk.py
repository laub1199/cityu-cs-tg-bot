from modules.tginstatracker import insta_tracker
from telegram import InlineKeyboardButton, InlineKeyboardMarkup


def nhk(update, context):
    username = 'nfts.hk'
    profile = insta_tracker.get_post(username)
    url = "https://www.instagram.com/p/" + profile['shortcode'] + "/"
    text = 'Check out ' + username + '\'s latest post!'
    keyboard = InlineKeyboardMarkup.from_button(
        InlineKeyboardButton(text=text, url=url)
    )
    context.bot.send_photo(chat_id=update.message.chat.id, photo=profile['photo_url'], reply_markup=keyboard, caption='NFT與區塊鏈資訊平台﹐教授相關知識﹐致力推廣香港出品嘅非同質化代幤﹐介紹有實際應用嘅project')
