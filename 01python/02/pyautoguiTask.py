import pyautogui

ext = pyautogui.locateOnScreen('ext.png')
pyautogui.moveTo(ext) 
pyautogui.click()
pyautogui.sleep(1)

search = pyautogui.locateOnScreen('search.png')
pyautogui.moveTo(search) 
pyautogui.click()
pyautogui.sleep(1)
pyautogui.write('clangd')
pyautogui.sleep(1)
pyautogui.moveTo(278, 250, duration=1) 
pyautogui.sleep(1)
pyautogui.click()
