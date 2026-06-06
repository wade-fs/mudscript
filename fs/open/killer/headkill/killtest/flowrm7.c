//花園迷陣第六型房間，正確方向是西方
//因為檔路的並不是三棵夾竹桃，必須依照十丈反左的理論
inherit ROOM;
string npc_name;
void create()
{
set("short", "花園迷陣");
set("long", @LONG
	在你眼前的是一大片夾竹桃，正開著粉紅色的花朵，微風輕拂，枝條搖曳。
	婆娑起舞，奼紫嫣紅，輕舞波浪的旋律，不由得令人癡醉。
	陪伴花草的是一堆堆布置完美的綠石，有了這些小山高的石堆，
	將此景色點綴的更無懈可擊，石堆與花之間有著參差不齊的羊腸小徑。
	在你眼前有一個石堆檔路，在十丈之外有一些景色如下。
	東方種有兩棵夾竹桃，西方種有兩棵夾竹桃，北方種有兩棵夾竹桃，
	    (請打move east,north,south,west任一方向)

LONG );
set("no_transmit",2);
setup();
}
void init()
{
  int i;
 object guard,me;

 i=random(4); 
 if(interactive(me = this_player()))
 {
  switch(i)
  {
	case 0:
	{
		guard=new("/open/killer/headkill/npc/hoga.c");
		guard->move("/open/killer/headkill/killtest/flowrm7.c");
		npc_name="ice river";
		break;
	}
	case 1:
	{
		guard=new("/open/killer/headkill/npc/shun.c");
		guard->move("/open/killer/headkill/killtest/flowrm7.c");
		npc_name="shun";
		break;
	}
	case 2:
	{
		guard=new("/open/killer/headkill/npc/seiya.c");
		guard->move("/open/killer/headkill/killtest/flowrm7.c");
		npc_name="seiya";
		break;
	}
	case 3:
	{
		guard=new("/open/killer/headkill/npc/ikki.c");
		guard->move("/open/killer/headkill/killtest/flowrm7.c");
		npc_name="ikki";
		break;
	}
	case 4:
	{
		guard=new("/open/killer/headkill/npc/shuryu.c");
		guard->move("/open/killer/headkill/killtest/flowrm7.c");
		npc_name="shuryu";
		break;
	}
  }
 }
  add_action("do_move", "move");
}

int do_move(string arg)
{
  int way;
  object me=this_player();
  object ob=this_object();

  if (!arg)
     return notify_fail("選擇一個你要去的方向吧。\n");
 if(present(npc_name,environment(me))) 
     return notify_fail("小子，先打倒守衛再說\n");	

  if ((arg == "east") || (arg == "north") || (arg == "south"))
  {
    me->set_temp("killrun",0);
    me->move(__DIR__"flowrm1.c");
    return 1;
  }
  if (arg == "west")
  {//表示方向正確
    if (me->query_temp("killrun") > 10)
    {
      me->move(__DIR__"flowrm8.c");
      return 1;
    }
    else
	{
		way=random(8);
		me->add_temp("killrun",1);
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
			case 6:
			{
				me->move(__DIR__"flowrm7a.c");
				return 1;
			}
			case 7:
			{
				me->move(__DIR__"flowrm7b.c");
				return 1;
			}
	}  //switch block
}		//else block
}  //檢查正確方向的block
return notify_fail("挖勒，你移動的是哪一個方向呀！\n");
}
