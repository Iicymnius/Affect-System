#if app.AFFECT_SYSTEM:
import uiScriptLocale

ROOT_PATH = "d:/ymir work/ui/affect_gui/"
BUTTON_PATH = "d:/ymir work/ui/affect_system/"

def create_button(name, x, y, image):
	return {
		"name": name,
		"type": "button",
		"x": x,
		"y": y,
		"horizontal_align": "center",
		"default_image": BUTTON_PATH + image,
		"over_image": BUTTON_PATH + image,
		"down_image": BUTTON_PATH + image
	}

window = {
	"name": "Affect_Panel",
	"x": 0,
	"y": 15,
	"style": ("movable", "float"),
	"width": 280,
	"height": 252,
	"children": (
		{
			"name": "board",
			"type": "board",
			"style": ("attach", "ignore_size"),
			"x": 0,
			"y": 0,
			"horizontal_align": "center",
			"vertical_align": "center",
			"width": 280,
			"height": 252,
			"children": (
				# Title Bar
				{
					"name": "TitleBar",
					"type": "titlebar",
					"style": ("attach",),
					"x": 6,
					"y": 6,
					"width": 265,
					"color": "yellow",
					"children": (
						{
							"name": "TitleName",
							"type": "text",
							"x": 0,
							"y": 3,
							"horizontal_align": "center",
							"text": "Efekt Tablosu",
							"text_horizontal_align": "center",
						},
					),
				},

				{
					"name": "Character_Info_Bar",
					"type": "image",
					"x": 0,
					"y": 35,
					"horizontal_align": "center",
					"image": ROOT_PATH + "public_affect.tga",
				},
				{
					"name": "Character_Info",
					"type": "text",
					"x": -30,
					"y": 37,
					"horizontal_align": "center",
					"text": "Bilgilendirme",
				},
				{"name":"text1", "type":"text", "x":20, "y":55, "text": "Hoşgeldin, bu ekrandan üstüne istediğin efekti verip"},
				{"name":"text2", "type":"text", "x":20, "y":65, "text": "kaldırabilirsin. Efektler karakterine işler, zırha veya"},
				{"name":"text3", "type":"text", "x":20, "y":75, "text": "kostüme değil."},

				{"name": "Item_Bar", "type": "image", "x": 40, "y": 90, "image": ROOT_PATH + "private_leftNameImg.sub"},
				{"name": "Item_Text", "type": "text", "x": 75, "y": 93, "text": "Gerekli Eşya"},
				{"name": "Character_Info_Bar", "type": "image", "x": 175, "y": 100, "image": "d:/ymir work/ui/public/Slot_Base.sub"},
				{"name": "Item_Slot", "type": "image", "x": 175, "y": 100, "image": ROOT_PATH + "27991.tga"},
				{"name": "Item_Name_Back", "type": "image", "x": 40, "y": 121, "image": "d:/ymir work/ui/public/parameter_slot_03.sub"},
				{"name": "Item_Name", "type": "text", "x": 43, "y": 122, "text": "Su Taşı (1x)/3 Gün"},

				{"name": "Character_Info_Bar", "type": "image", "x": 0, "y": 160, "horizontal_align": "center", "image": ROOT_PATH+"public_affect.tga"},
				{"name": "Character_Info", "type": "text", "x": -40, "y": 162, "horizontal_align": "center", "text": "Efekt ve Renk Stilleri"},

				{"name": "thinboard", "type": "thinboard", "x": 10, "y": 180, "width": 260, "height": 50},

				create_button("Desert1", 30, 185, "yellow_box.png"),
				create_button("Desert2", 50, 185, "orange_box.png"),
				create_button("Desert3", 70, 185, "white_box.png"),
				create_button("Desert4", 90, 185, "orange_box.png"),
				create_button("Desert5", -90, 210, "pink_box.png"),
				create_button("Desert6", -70, 210, "purple_box.png"),
				create_button("Desert7", -50, 210, "green_box.png"),
				create_button("Desert8", -30, 210, "turquoise_box.png"),
				create_button("Desert9", -10, 210, "red_box.png"),
				create_button("AffectClear", 90, 210, "clear_button.png"),

				create_button("Tornado1", 10, 210, "tornado_yellow.png"),
				create_button("Tornado2", 30, 210, "tornado_blue.png"),
				create_button("Tornado3", 50, 210, "tornado_red.png"),
				create_button("Tornado4", 70, 210, "tornado_green.png"),

				create_button("Electric1", -90, 185, "red_electric.png"),
				create_button("Electric2", -70, 185, "yellow_electric.png"),
				create_button("Electric3", -50, 185, "green_electric.png"),
				create_button("Electric4", -30, 185, "blue_electric.png"),
				create_button("Electric5", -10, 185, "pink_electric.png"),
				create_button("Electric6", 10, 185, "white_electric.png"),
			),
		},
	),
}
