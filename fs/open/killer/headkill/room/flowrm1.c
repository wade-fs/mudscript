inherit ROOM;
void create()
{
set("short", "花園迷陣");
set("long", @LONG
	在你眼前的是一大片夾竹桃，正開著粉紅色的花朵，微風輕拂，枝條搖曳。
	婆娑起舞，奼紫嫣紅，輕舞波浪的旋律，不由得令人癡醉。
	陪伴花草的是一堆堆布置完美的綠石，有了這些小山高的石堆，
	將此景色點綴的更無懈可擊，石堆與花之間有著參差不齊的羊腸小徑。
	東方種有三棵夾竹桃，西方種有兩棵夾竹桃，北方只有一個石頭，

LONG );
set("exits", ([ /* sizeof() == 2 */
  "north": "/open/killer/room/outr3.c",
  "east" : "/open/killer/room/outr3.c",
  "west" : __DIR__"flowrm2.c",
  "south": "/open/killer/room/outr3.c",
]));

setup();
}

int valid_leave(object me, string dir)
{
  if (dir != "west") 
  {
    me->set_temp("flowrun",0);
    return 1;
  }
//以下表示走對正確方向
  if (me->query_temp("head") < 1)
  {//不是解謎者不可以進花園迷陣
    me->move("/open/killer/room/outr3.c");
    return 0;
  }
  //這裡是花園迷陣的開頭，走錯就必須重來
  //下一個房間才開始檢查是不是走夠路了！
  me->set_temp("flowrun",1);
  return 1;
}
