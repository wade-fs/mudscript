#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_SPELL;
void create() {seteuid(getuid());}
int cast(object me, int number,string name)
{
  
	object mob,room=environment(me),weapon;
	int needlevel, manacost,spell,invcost,i,funlvl;
	string filename;

  if( !me->is_fighting() )
       return notify_fail("戰鬥中才能召喚鬼神！\n");
  if(!me->query("spells/invocation/level") ) 
       return 0;
  if (!objectp (weapon = me->query_temp ("weapon")) ||
                  weapon->query("skill_type") != "whip")
       return notify_fail("請先裝備拂塵!!\n");

  if( me->query("class")!= "taoist" )
       return notify_fail("只有道士才用的出這種法術。\n");
	   if(me->query_temp("have_hawk"))
        return notify_fail("一次只能召換一種喔!\n");
  if( me->query("sen") < 30 )
       return notify_fail("你的精神無法集中！\n");	
	me->start_busy(1);
	filename = __DIR__"npc/" + name;
	if( file_size(filename+".c") < 0 )
		return notify_fail("沒有這種東西可供招喚。\n");
	needlevel= filename->needlevel ();
        manacost = (filename->manacost ())*number;
	invcost = (filename->invcost ())*number;
        spell = me->query_skill("spells");
	funlvl = me->query ("spells/invocation/level");
/*     
  if(filename== __DIR__"npc/king" && me->query("quests/supertao")!=1) {     
     return 0;
  }
*/
  if (funlvl < needlevel ) {
     write("你的熟練等級還不夠ㄛ....這種鬼神你召喚不動!!\n");
     return 1;
  }
  if( me->query_temp ("invocation")+invcost > spell/2) {
     write("你已經召喚太多了，去練練洛書河圖來增加你的召喚數目吧!!\n");
     return 1;
  }
  if (!needlevel) {
     write("沒這位鬼神。\n");
     return 1;
  }

  if (me->query ("mana") < manacost) {
     write("你的法力已經耗盡....\n");
     return 1;
  }
  message_vision("\n\n$N喃喃地念了幾句咒語。\n", me);
  if( funlvl < 100 )
  spell_improved ("invocation", random(funlvl*10) );
  me->receive_damage("sen",random(25));
  me->add ("mana", -manacost);
  me->start_busy(1); 
  for(i=0;i < number;i++) {
  seteuid(getuid());
  mob = new(filename);
  mob->move (room);
  mob->besummon(me,room);
 }  
  return 1;

}
