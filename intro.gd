extends Control

func _on_StartButton_pressed() -> void:
    # Load your Upload Page
    var upload_scene = load("res://UploadPage.tscn").instantiate()
    get_tree().change_scene_to_packed(upload_scene)