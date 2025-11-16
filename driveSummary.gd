extends Control

var results_json_text: String = ""
var results_data

func load_results(json_text: String) -> void:
    results_json_text = json_text

    var parsed = JSON.parse_string(json_text)
    if parsed == null:
        print("JSON parse error!")
        return

    results_data = parsed
    update_ui()


func update_ui() -> void:
    if results_data.has("score"):
        $ScoreLabel.text = "Score: " + str(results_data.score)

    if results_data.has("events"):
        for e in results_data.events:
            add_list_item(e)


func add_list_item(text: String) -> void:
    var label = Label.new()
    label.text = text
    label.autowrap = true
    $ResultsScroll/ResultsList.add_child(label)