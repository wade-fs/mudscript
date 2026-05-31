#define ROOT_DIR "/data/new_board/"

inherit ITEM;
inherit F_SAVE;

void create()
{
  set_name("BBS 系統索引檔", ({ "board_index", }) );
  if (!restore()) {
    set("long", "天聽自我民聽，眾巫師有話就留，沒話快滾。\n");
    set("unit", "個");

    set ("save_file", ROOT_DIR"BBS_desc");
  }

  setup();
}

string query_save_file()
{
        return query("save_file");
}
