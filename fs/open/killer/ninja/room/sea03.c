//一般外海區域 主路線，非特殊 區域 
inherit ROOM;

void create()
{
set("short", "外海");
set("long", @LONG

	一望無際的大海，讓人不禁心胸開闊起來，且豪氣萬丈。
	茫茫的大海中，讓你不知道該何去何從，為了避免迷路，
	還是乖乖的按照，一般的路線前進吧........
	
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"sea02.c",
]));
set("no_transmit",2);
setup();
}

void init()
{
  int i;
  object guard;
  object me=this_player();

 if(interactive(me) && (random (4) < 1 ))
 {//25%的敵人出現機率
  i=random(5); 
  // 由 五種類的敵人裡面選出合適的
  // 一般區域的話，敵人類型多，但是沒有好寶物，但是常常會出現
  switch(i)
  {
	case 0:
	//直接送到房間而不是玩家所在房間
        //這是避免，玩家房間在還沒建立之前，先送物件到該房間
		guard=new(__DIR__"npc/normal01.c");
		guard->move(environment(me));
		break;
	case 1:
		guard=new(__DIR__"npc/normal01");		
		break;
	case 2:
		guard=new(__DIR__"npc/normal01");
		break;
	case 3:
		guard=new(__DIR__"npc/normal01");
		break;
	case 4:
		guard=new("/open/killer/headkill/npc/shuryu.c");
		break;
  }//SWITCH
  guard->move(environment(me));
 }//IF
}


int valid_leave(object me, string dir)
 {
 object target;
 
// target = offensive_target(me);
 if(me->is_fighting())
 //if(present(guard->query("id"),environment(me)))
 {
    if (random(10) < 5)
    {
    	me->start_busy(2);
    	return notify_fail("逃跑失敗，身形為之一滯!!!!\n");
    }
  }
  return 1;
}
