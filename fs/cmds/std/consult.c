// consult.c
// by airke 1998


#include <spell_from.h>
#include <spell_level.h>
#include <spell_basic.h>
#include <skill.h>

string *reject_msg = ({
  "說道﹕您太客氣了﹐這怎麼敢當﹖\n",
  "像是受寵若驚一樣﹐說道﹕請教﹖這怎麼敢當﹖\n",
  "笑著說道﹕您見笑了﹐我這點雕蟲小技怎夠資格「指點」您什麼﹖\n",
});

varargs int main(object me, string arg)
{
  string spell, teacher,sp_from;
 
  object ob;

  seteuid(getuid());
  

  if(!arg || sscanf(lower_case(arg), "%s from %s", spell, teacher)!=2 )
    return notify_fail("指令格式﹕consult <法術> from <某人>\n");

  if (spell=="hellfire") return notify_fail("這個法術不能這樣學喔");

  if( me->query("spells/"+spell+"/level") )
    return notify_fail("你早就會這項法術了，不必再學。\n");
  
  if( me->is_fighting() )
    return notify_fail("臨陣磨槍﹖來不及啦。\n");

  if( !(ob = present(teacher, environment(me))) || !ob->is_character())
    return notify_fail("你要向誰求教﹖\n");
  
  if( !living(ob) )
    return notify_fail("嗯....你得先把" + ob->name() + "弄醒再說。\n");
  
  if(wizardp(ob))
    return notify_fail("不能跟巫師學法術。\n");
  
  if ( !ob->query("spells/"+spell+"/level") )
    return notify_fail("對方不會這項法術，請用spells <人名> 查看。\n");
  
  if ( !spell_from[spell] )
    return notify_fail("沒有這種法術!!\n");

    if ( !me->is_apprentice_of(ob) ) {
      if ((string)me->query("family/family_name") !=
	  (string)ob->query("family/family_name") ||
	  (int)ob->query("family/privs") != -1)
      {
        if(me->query("class") != ob->query("class") ||
 	  !me->query("class") || !ob->query("class") )
        {
          notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
          if( !(ob->recognize_apprentice(me)) ) return 0;
        }
      }
    }
    else {
      if( me->query("class") != ob->query("class") ||
         !me->query("class") || !ob->query("class") )
      {
  	return notify_fail(ob->query("name")+"說：\n"+
 		 "你和我是不同的職業，恕我不能教你。\n");
      }
    }
    if (!ob->query("guild_master") && !me->is_apprentice_of(ob) && 
      !(ob->query("env/傳授/all/all") || ob->query("env/傳授/all/"+spell) ||
       ob->query("env/傳授/"+me->query("id")+"/all") || 
       ob->query("env/傳授/"+me->query("id")+"/"+spell)))
    return notify_fail("對方看起來並不想教你這項法術！\n");

  
  sp_from = spell_from[spell];
  if ( me->query_skill(spell_basic[sp_from]) < spell_level[spell] )
    return notify_fail(ob->query("name")+"說道: 你的"+to_chinese(sp_from)+"知識仍嫌不足，無法領會此法精妙所在。\n");
  if (userp(ob))
    tell_object(ob, sprintf("%s向你請教有關「%s」的技巧。\n",
    	me->name(), to_chinese(spell)));
  printf("你向%s請教「%s」的技巧。\n", ob->name(), to_chinese(spell));
  printf("\n聽了%s一番解說後﹐\n你終於領悟了「%s」施法訣竅!!\n", ob->name(),to_chinese(spell));
        
  me->set("spells/"+spell+"/level",1);
    
   
  return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : consult <法術> from <某人>
指令說明 :
           這個指令可以讓你向別人請教有關某一種法術的施法技巧
     對於已對法術有相當了解的你來言，這個指令則是將你所學的法
     術知識，加以實際化的的指令，透過跟大師級的求教，你將學會
     法力的使用，而不光只是紙上談兵而已。      
         
           至於如何知道你能從對方學到什麼技能﹐如果對方是你
     的師父﹐可以用 spells 指令直接查看﹐如果不是你的師父﹐
     那麼通常會有其他的提示﹐你只好自己想辦法。
其他參考 :
           practice、study、learn、cast、conjure
HELP );
        return 1;
}
