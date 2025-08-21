#add;

if app.AFFECT_SYSTEM:
	import uiaffectsystem

#find;

		self.interface = None

#add below;

		if app.AFFECT_SYSTEM:
			self.AffectSystem = uiaffectsystem.Affect()

#find again;

		onPressKeyDict[app.DIK_F4]	= lambda : self.__PressQuickSlot(7)

#add below;

		if app.AFFECT_SYSTEM:
			onPressKeyDict[app.DIK_F5] = lambda: self.AffectSystem.Hide() if self.AffectSystem.IsShow() else self.AffectSystem.Show()
