import webbrowser
from time import ctime
from datetime import datetime
import os
import playsound
from gtts import gTTS
import random
import speech_recognition as sr
import firelink
import sys

class voice_assistant:
    recognizer = sr.Recognizer()
  
    def record_audio(self):
        with sr.Microphone() as source:
            print("Listening...")
            self.recognizer.adjust_for_ambient_noise(source)
            audio = self.recognizer.listen(source)
        return audio

    def recognize_speech(self, audio):
        text = ""
        try:
            text = self.recognizer.recognize_google(audio, language="ar-EG")
            print(f"You said: {text}")
        except sr.UnknownValueError:
            print("Sorry, I couldn't understand that.")
        except sr.RequestError:
            print("Sorry, there was an error processing your request.")
        return text

    def speak(self, text):
        tts = gTTS(text=text, lang='ar', slow=False)
        tts.save("audio.mp3")
        playsound.playsound("audio.mp3")

    def open_link(self):
        self.speak('اختار الموقع')
        print("Say...")
        audio_data = self.record_audio()
        print("Recognizing speech...")
        text = self.recognize_speech(audio_data)
        websites = {
            "فيسبوك": firelink.facebook_link,
            "جوجل": firelink.google_link,
            "يوتيوب": firelink.youtube_link,
            "تويتر": firelink.twitter_link
        }
        if text in websites:
            url = websites[text]
            firelink.firefox(url)
        else:
            print("Invalid choice. Please try again.")

    def get_current_time(self):
        now = datetime.now()
        current_time = now.strftime("%H:%M:%S")
        print(current_time)
        self.speak(current_time)

    def greeting(self, text):
        if text in ['صباح الخير', 'صباح الفل', 'صباح النور']:
            self.speak('صباح النور')
        elif text in ['مساء الخير', 'مساء الفل', 'مساء النور']:
            self.speak('مساء النور')
        else:
            self.speak('اهلا')

    def Alexa(self):
        print("Say something...")
        audio_data = self.record_audio()
        print("Recognizing speech...")
        recognized_text = self.recognize_speech(audio_data)
        if recognized_text in ['صباح الخير', 'صباح الفل', 'صباح النور', 'مساء الخير', 'مساء الفل', 'مساء النور', 'اهلا', 'هاي', 'هالو']:
            self.greeting(recognized_text)
        elif recognized_text in ["الوقت", "الساعة كام", "ساعة", "الساعة"]:
            self.get_current_time()
        elif recognized_text in ["موقع", "افتحي موقع","افتحي موقع", "ويب سايت"]:
            self.open_link()
        elif recognized_text in ["اقفل", "اقفلي", "close", "اطفي"]:
            sys.exit()

if __name__ == "__main__":
    assistant = voice_assistant()
    while True:
        assistant.Alexa()
