import instaloader
import os
from instaloader import Profile
from telegram.ext import CallbackContext
from telegram import InlineKeyboardButton, InlineKeyboardMarkup
from dotenv import load_dotenv


class _InstaTracker:
    def __init__(self, ig_username, ig_password, group_list=None, target_username_list=None):
        self._insta = instaloader.Instaloader()
        self._insta.login(ig_username, ig_password)
        self._group_list = group_list if not group_list is None else []
        self._target_username_list = target_username_list if not target_username_list is None else []
        if target_username_list is not None:
            self._latest_post = self._init_latest_post()

    def _init_latest_post(self):
        latest_post = {}
        for username in self._target_username_list:
            if username not in latest_post:
                latest_post[username] = self._crawl_latest_post(username)
        return latest_post

    def _crawl_latest_post(self, username):
        profile = Profile.from_username(self._insta.context, username)
        for post in profile.get_posts():
            return {
                'shortcode': post.shortcode,
                'photo_url': post.url,
                'caption': post.caption
            }

    def insta_track(self, context: CallbackContext):
        print('=======================================================')
        print('Running insta_track function...')
        for username in self._target_username_list:
            instant_flag = False
            profile = Profile.from_username(self._insta.context, username)
            # for instant control
            # if username == 'cityusu':
            #     instant_flag = True
            for post in profile.get_posts():
                shortcode = post.shortcode
                print('[Tracking] {} - {}'.format(username, self._latest_post[username]))
                print('[Latest post]: {}'.format(shortcode))
                url = "https://www.instagram.com/p/" + shortcode + "/"
                photo_url = post.url
                text = 'Check out ' + username + '\'s latest post!'
                keyboard = InlineKeyboardMarkup.from_button(
                    InlineKeyboardButton(text=text, url=url)
                )
                caption = post.caption
                if self._latest_post[username]['shortcode'] != shortcode or instant_flag:
                    print('[New post commit] {} from {} to {}'.format(username, shortcode, self._latest_post[username]['shortcode']))
                    self._latest_post[username]['shortcode'] = shortcode
                    self._latest_post[username]['photo_url'] = photo_url
                    self._latest_post[username]['caption'] = caption
                    for id in self._group_list:
                        context.bot.send_photo(chat_id=id, photo=photo_url, reply_markup=keyboard, caption=caption)
                break
        print('=======================================================')

    def get_post(self, username):
        return self._latest_post[username]


load_dotenv()
APP_ENV_IS_TEST = True if os.environ.get("APP_ENV") == 'test' else False
group_list = [-1001338851560] if APP_ENV_IS_TEST else [-1001278050153]
target_username_list = ['cityusu', 'cityucss_nebulae', 'cityusu_welfare', 'hkcityu.info', 'cityusu.cbc', 'cityusu.edb']

insta_tracker = _InstaTracker(
    os.environ.get("INSTA_TRACK_USERNAME"),
    os.environ.get("INSTA_TRACK_PASSWORD"),
    group_list=group_list,
    target_username_list=target_username_list
)
