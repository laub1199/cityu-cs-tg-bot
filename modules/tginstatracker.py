import instaloader
from instaloader import Profile
from telegram.ext import CallbackContext
from telegram import InlineKeyboardButton, InlineKeyboardMarkup, Update


class InstaTracker:
    def __init__(self, ig_username, ig_password, group_list=None, target_username_list=None):
        self.insta = instaloader.Instaloader()
        self.insta.login(ig_username, ig_password)
        self.group_list = group_list if not group_list is None else []
        self.target_username_list = target_username_list if not target_username_list is None else []
        if target_username_list is not None:
            self.latest_post = self.init_latest_post()

    def init_latest_post(self):
        latest_post = {}
        for username in self.target_username_list:
            if username not in latest_post:
                latest_post[username] = self.get_latest_post(username)
        return latest_post

    def get_latest_post(self, username):
        profile = Profile.from_username(self.insta.context, username)
        for post in profile.get_posts():
            return post.shortcode

    def insta_track(self, context: CallbackContext):
        for username in self.target_username_list:
            profile = Profile.from_username(self.insta.context, username)
            for post in profile.get_posts():
                shortcode = post.shortcode
                url = "https://www.instagram.com/p/" + shortcode + "/"
                photo_url = post.url
                text = 'Check out ' + username + '\'s latest post!'
                keyboard = InlineKeyboardMarkup.from_button(
                    InlineKeyboardButton(text=text, url=url)
                )
                caption = post.caption
                if self.latest_post[username] != shortcode:
                    self.latest_post[username] = shortcode
                    for id in self.group_list:
                        context.bot.send_photo(chat_id=id, photo=photo_url, reply_markup=keyboard, caption=caption)
                break

    def add_group(self, group_id):
        self.group_list.append(group_id)

    def remove_group(self, group_id):
        self.group_list.remove(group_id)

    def add_target_user(self, username):
        self.target_username_list.append(username)
        self.latest_post[username] = self.get_latest_post(username)

    def remove_target_user(self, username):
        self.target_username_list.remove(username)
        del self.latest_post[username]
