inherit ROOM;

void create()
{
 set("short","太君山腳");
 set("long",@LONG
樹木蒼翠，時有昆蟲獸鳴聲，不遠處正有幾個乞丐布袋裡
拿出小蛇，有黑有紅，有長有短，附近全是過膝的長草，
或許已經有幾條小蛇埋伏在你身邊了，你心下不禁慌亂，
只覺毛骨悚然，若不想給咬上一口，身中奇毒，最好夾起
尾巴，迅速逃離此處吧。

LONG);
 set("exits",([
 "east" : __DIR__"room06.c",
 "north" : __DIR__"room04.c"
 ]));
 setup();
}
