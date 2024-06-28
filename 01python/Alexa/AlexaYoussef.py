import webbrowser
from time import ctime
import os
import playsound
from gtts import gTTS
import random
import speech_recognition as sr
import threading

class VoiceAssistant:
    recognizer = sr.Recognizer()

    def record_audio(self):
        with sr.Microphone() as source:
            print('Listening...')
            self.recognizer.adjust_for_ambient_noise(source)
            audio = self.recognizer.listen(source)
        return audio
    
    def recognize_speech(self, audio):
        try:
            text = self.recognizer.recognize_google(audio, language='ar-EG')
            print(f'You said: {text}')
            return text
        except sr.UnknownValueError:
            print("Sorry, I couldn't understand that.")
            return ""
        except sr.RequestError:
            print("Sorry, there was an error processing your request.")
            return ""
    def Respond(voice_data):
        global alexa
# Instantiate the class
alexa = VoiceAssistant()

# Record audio
audio_alexa = alexa.record_audio()

# Recognize speech
alexa.recognize_speech(audio_alexa)