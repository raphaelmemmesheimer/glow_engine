import Editors
from GlowEditorfMainEditor import GlowEditorfMainEditor
import wx

class oneMinutePython(wx.App):

	def OnInit(self):

		self.m_frame = GlowEditorfMainEditor(None)
		self.m_frame.Show()
		#self.SetTi
		self.SetTopWindow(self.m_frame)
		return True

app = oneMinutePython(0)
app.MainLoop()
