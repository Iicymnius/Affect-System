#if app.AFFECT_SYSTEM:
import ui
import wndMgr
import net
import constInfo
import playerSettingModule

class Affect(ui.ScriptWindow):

	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.affect_buttons = {}
		self.__LoadDialog()
		self.OnUpdate()

	def __del__(self):
		ui.ScriptWindow.__del__(self)

	def Show(self):
		self.SetCenterPosition()
		self.SetTop()
		self.__LoadDialog()
		ui.ScriptWindow.Show(self)

	def __LoadDialog(self):
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self, "UIScript/affectsystem.py")

			self.GetChild("TitleBar").SetCloseEvent(ui.__mem_func__(self.Close))

			affect_names = [
				"Desert1","Desert2","Desert3","Desert4","Desert5","Desert6",
				"Desert7","Desert8","Desert9","AffectClear",
				"Electric1","Electric2","Electric3","Electric4","Electric5","Electric6",
				"Tornado1","Tornado2","Tornado3","Tornado4"
			]

			for name in affect_names:
				btn = self.GetChild(name)
				self.affect_buttons[name] = btn

			self.affect_map = {
				"Desert1": "a", "Desert2": "b", "Desert3": "c", "Desert4": "d",
				"Desert5": "e", "Desert6": "f", "Desert7": "g", "Desert8": "h",
				"Desert9": "j", "AffectClear": "clear",
				"Electric1": "k", "Electric2": "l", "Electric3": "m",
				"Electric4": "n", "Electric5": "o", "Electric6": "p",
				"Tornado1": "q", "Tornado2": "r", "Tornado3": "s", "Tornado4": "t"
			}

			def bind_button(button, code):
				if code == "clear":
					button.SetEvent(ui.__mem_func__(self.ClearAffects))
				else:
					button.SetEvent(lambda c=code: self.SendAffect(c))

			for name, code in self.affect_map.items():
				btn = self.affect_buttons.get(name)
				if btn:
					bind_button(btn, code)

			self.SetPositionCenter()

		except Exception:
			import exception
			exception.Abort("AffectSystem.__LoadDialog.BindObject")

	def SetPositionCenter(self):
		self.SetPosition(
			(wndMgr.GetScreenWidth() / 2) - (self.GetWidth() / 2),
			(wndMgr.GetScreenHeight() / 2) - (self.GetHeight() / 2)
		)

	def Close(self):
		constInfo.AFFECT_SYSTEM = 0
		self.Hide()

	def OnPressEscapeKey(self):
		self.Close()
		return TRUE

	def OnUpdate(self):
		return TRUE

	def SendAffect(self, code):
		net.SendChatPacket("/affect_give %s" % code)
		self.Close()

	def ClearAffects(self):
		net.SendChatPacket("/affect_delete")
		self.Close()
