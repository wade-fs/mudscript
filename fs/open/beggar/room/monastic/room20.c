inherit ROOM;

void create()
{
 set("short","東廂房");
 set("long",@LONG
  這裡是丐幫專為武林中人到此遊玩所特設的廂房，房間
  雖然不大，不過卻整齊有致，乾乾淨淨，眺望窗外，還
  可以看到太湖美麗的景色，尤其是太陽西下時的夕陽，
  映在湖面上更讓人有股心曠神怡，彷彿置身仙境的感覺。

LONG);
 set("exits",([
 "east" : __DIR__"room21.c",
 "west" : __DIR__"room19.c",
 "north" : __DIR__"room11.c",
 "south" : __DIR__"room28.c"
 ]));
 setup();
}
