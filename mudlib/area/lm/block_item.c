// mudlib/area/lm/block_item.c
// Minecraft 方塊物品

inherit "/std/object.c";

string block_type;

void create() {
    ::create();
    block_type = "stone";
}

void set_block_type(string t) {
    block_type = t;
    set_name(t);
    set_short(t + " 方塊");
    set_long("一塊 " + t + "，可以放置到世界中。\n");
    // 🚀 關鍵：將類型加入 ID 列表，方便 place 指令搜尋
    set_id(({ t, t + "_block", "block", "mc_block" }));
}

string query_block_type() { return block_type; }

string query_category() { return "Special"; }
