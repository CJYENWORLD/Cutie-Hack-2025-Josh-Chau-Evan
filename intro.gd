extends Control

func _ready() -> void:
    pass


# When the upload button is clicked
func _on_UploadButton_pressed() -> void:
    $FileDialog.popup()   # open the file explorer


# When the user selects a file in the FileDialog
func _on_FileDialog_file_selected(path: String) -> void:
    print("Selected file:", path)
    process_csv(path)     # send the file to backend


# Run your C++ program from Godot
func process_csv(path: String) -> void:
    var output := []
    
    # IMPORTANT:
    # "scorecalc" must be your compiled C++ binary placed in your Godot project folder
    var exit_code = OS.execute("res://scorecalc", [path], output)

    if exit_code != 0:
        print("C++ backend error:", exit_code)
        return

    var json_string := output.join("\n")
    go_to_summary(json_string)


# Switch to the drive summary screen and send data
func go_to_summary(json_string: String) -> void:
    var scene := load("res://drive_summary.tscn").instantiate()
    scene.load_results(json_string)
    get_tree().change_scene_to_packed(scene)