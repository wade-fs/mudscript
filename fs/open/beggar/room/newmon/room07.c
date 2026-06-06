inherit ROOM;

void create()
{
 set("short","訓練場");
 set("long",@LONG
這裡是丐幫訓練有成的弟子加強訓練的地方，你看到這裡
的弟子和外頭的不同，這裡的弟子身上都背有布袋，有一
個、兩個‧‧‧一直到八個，這裡就是丐幫有袋弟子修練
的地方。
  
LONG);
 set("exits",([
 "north" : __DIR__"room22.c",
]));


setup();
}
