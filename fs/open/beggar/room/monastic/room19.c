inherit ROOM;

void create()
{
 set("short","走道");
 set("long",@LONG
  兩旁掛滿太湖風光景色的畫圖，如幻似真，你靜靜的觀賞
  著每一幅圖，慢慢的你也融入畫中，就像是你現在正坐在
  太湖旁觀賞景色一樣，看了許久，你不禁嘖嘖稱讚，丐幫
  中竟然也有這繪畫奇才。

LONG);
 set("exits",([
 "east" : __DIR__"room20.c",
 "west" : __DIR__"room18.c",
 "south" : __DIR__"room27.c"
 ]));
 setup();
}
