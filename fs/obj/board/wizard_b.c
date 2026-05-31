// query_b.c

inherit BULLETIN_BOARD;

void create()
{
         set_name("巫師打屁哈拉版",({ "wizard board ","board"}));
        set("location","/open/wiz/hall1");
        set("board_id","wizard_b");
	set("long", @LONG
這是一個專門給巫師留有關玩家事項的布告欄, 例如舉發某玩家有違規
事項, 某玩家的檔有問題等等。
LONG);
	setup();
    set("capacity", 300);
}
