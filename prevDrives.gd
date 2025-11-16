extends Control

@onready var drives_list = $ScrollContainer/DrivesList

func load_json_drives(data):
    for d in data:
        add_drive_entry(d["summary"])

func add_drive_entry(text: String):
    var label = Label.new()
    label.text = text
    label.add_theme_font_size_override("font_size", 20)
    drives_list.add_child(label)