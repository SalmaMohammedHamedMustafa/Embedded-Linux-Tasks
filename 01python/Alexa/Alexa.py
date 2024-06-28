# import library
import webbrowser
from time import ctime
from datetime import datetime
import os
import playsound
from gtts import gTTS
import random
import speech_recognition as sr
import threading
import firelink

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
            # text = self.recognizer.recognize_whisper(audio, language="arabic")
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



    def open_link (self,text):
        websites ={
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
        assistant.speak(current_time)


    #def get_weather(self):



if __name__ == "__main__":
    assistant = voice_assistant()
    
    print("Say something...")
    audio_data = assistant.record_audio()
    
    print("Recognizing speech...")
    recognized_text = assistant.recognize_speech(audio_data)

    #assistant.open_link(recognized_text)
    if(recognized_text== "الوقت" or "الساعة كام" or "ساعة" or "الساعة"):
        assistant.get_current_time();
    
    if recognized_text:
        print("Speaking out the recognized text...")
        assistant.speak(recognized_text)
