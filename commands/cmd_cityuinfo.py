from modules.tginstatracker import insta_tracker
from telegram import InlineKeyboardButton, InlineKeyboardMarkup


def cityuinfo(update, context):
    username = 'hkcityu.info'
    profile = insta_tracker.get_post(username)
    url = "https://www.instagram.com/p/" + profile['shortcode'] + "/"
    text = 'Check out ' + username + '\'s latest post!'
    keyboard = InlineKeyboardMarkup.from_button(
        InlineKeyboardButton(text=text, url=url)
    )
    context.bot.send_photo(chat_id=update.message.chat.id, photo=profile['photo_url'], reply_markup=keyboard, caption=profile['caption'])
