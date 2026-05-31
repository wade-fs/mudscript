// board.c
inherit BULLETIN_BOARD;
 
void create()
{
set_name("少林啟示錄",({"soulin board","board"}));
set("location","/open/soulin/room/big");
set("board_id","soulin_b");
set("long"," 一顆光溜溜的頭頂上布滿了密密麻麻的字!\n");
    setup();
    set("capacity",100);
    set("master",({ "minimum" }) );
}
