// Room: /open/hall/h_room11.c

inherit ROOM;

void create()
{
        set("short","廂房走道");
        set("long",@LONG
此處是廂房前的走道，在西邊有一盞大窗戶，空氣十分流通。寧靜
的氣氛，使人感到格外的舒暢～你的南方是三捕頭─秦  忌之廂房，而
北邊是二捕頭─朱火旺之廂房。
LONG);
        set("exits",([
  "east":__DIR__"h_room10",
  "north":__DIR__"h_room15",
  "south":__DIR__"h_room14",
]));

        setup();
}
