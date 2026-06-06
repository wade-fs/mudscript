inherit ITEM;
#include <ansi.h>
void create ()
{
set_name("最新科技人造人",({"super science robot","super","robot"}));
set("long","一個由創辦人所製造的最新科技產品，用來判斷競技場
的系統運行是否正常的超級電腦。\n");
set("unit","部");
set("no_get",1);
set("no_sac",1);
setup();
}

void init(object me,object ob) 
{
me=this_player();
ob=this_object();
if(interactive(me))
	{
	  if(!me->query("quest/start_game"))
	  {
	  tell_room(environment(ob),HIY + "查詢到不明物體入侵。危險！危險！\n" + NOR,me);
	  tell_room(environment(ob),HIY + "\n系統倒數三秒，預備攻擊目標『"HIW+me->query("name")+HIY"』。\n\n" + NOR);
	  call_out("time",3,me);
	  }
	  else
	  {
	    if(!present("npc08",environment(ob)))
	    {
	    object mob;
	    mob=new(__DIR__"npc08");
	    mob->move(environment(ob));
	    tell_room(environment(ob),HIW + "系統：戰鬥申請合格，NPC製作完成。\n" + NOR);
	    }
	    else
	    {
	    tell_room(environment(ob),HIR + "系統：戰鬥申請失敗，尚有NPC。\n" + NOR);
	    }
	  } 
	}
}

int time(object me,object ob)
{
ob=this_object();
tell_room(environment(me),HIY + "\n\n系統遠距離攻擊『" + HIR + "噴墨器" + HIY + "』預備完成！目標『"HIW+me->query("name")+HIY"』確認。\n" + NOR);
tell_room(environment(me),"\n\n"HIW+me->query("name")+"遭到強力的噴墨攻擊。\n\n" + NOR);
tell_object(me,HIW + "系統顯示：『請跟巫師firedancer說明你是如何進入的，以便修正BUG。』\n" + NOR);
me->set("title",HIY + "作弊天王" + NOR);
me->move(__DIR__"steeple");
tell_room(environment(ob),HIW + "\n系統顯示：入侵者已經受到懲罰，請繼續闖關。\n" + NOR);
}
