//花園迷陣第六型房間，正確方向是北方
//因為檔路的並不是三棵夾竹桃，必須依照十丈反左的理論
//不管十丈的景色是怎樣，反正遇到石頭就是往左邊（因為面向北邊，所以是朝西邊走）
inherit ROOM;
void create()
{
set("short", "花園迷陣");
set("long", @LONG
	在你眼前的是一大片夾竹桃，正開著粉紅色的花朵，微風輕拂，枝條搖曳。
	婆娑起舞，奼紫嫣紅，輕舞波浪的旋律，不由得令人癡醉。
	陪伴花草的是一堆堆布置完美的綠石，有了這些小山高的石堆，
	將此景色點綴的更無懈可擊，石堆與花之間有著參差不齊的羊腸小徑。
	在你眼前有三棵夾竹桃檔路，在十丈之外有一些景色如下。
	東方只有一個石頭，北方種有兩棵夾竹桃一旁有一堆石堆，
	西方種有兩棵夾竹桃，但無石堆在一旁。
    (請打move east,north,south,west任一方向)

LONG );
setup();
}
void init()
{
  add_action("do_move", "move");
}

int do_move(string arg)
{
  int way;
  object me=this_player();

  if (!arg)
     return notify_fail("選擇一個你要去的方向吧。\n");
  if ((arg == "east") || (arg == "west") || (arg == "south"))
  {
//  	message_vision("$N感到一陣眼花撩亂，看來是走錯方向了！\n", me);
    me->set_temp("flowrun",0);
    me->move(__DIR__"flowrm1.c");
    return 1;
  }
  if (arg == "north")
  {//表示方向正確
	if (me->query_temp("flowrun") > 9)
    {
      me->move(__DIR__"flowrm8.c");
      return 1;
    }
    else
	{
		way=random(6);
		me->add_temp("flowrun",1);
		switch (way)
		{
			case 0:
			{
				me->move(__DIR__"flowrm2.c");
				return 1;
			}
			case 1:
			{
				me->move(__DIR__"flowrm3.c");
				return 1;
			}
			case 2:
			{
				me->move(__DIR__"flowrm4.c");
				return 1;
			}
			case 3:
			{
				me->move(__DIR__"flowrm5.c");
				return 1;
			}
			case 4:
			{
				me->move(__DIR__"flowrm6.c");
				return 1;
			}
			case 5:
			{
				me->move(__DIR__"flowrm7.c");
				return 1;
			}
	}  //switch block
}
}  //檢查正確方向的block
return notify_fail("挖勒，你移動的是哪一個方向呀！\n");
} //function block

