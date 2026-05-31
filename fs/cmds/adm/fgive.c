// give.c
#include <carry.h>
//fixed by lum 7/11/1996 because 之前有人用中文加符號。
// fund 修改﹐限制玩者攜帶量以節省記憶體 (8/15/1996)
inherit F_CLEAN_UP;
int do_give(object me,object obj,object who,int force);
 
void create() { seteuid(getuid()); }
 
int main(object me,string arg)
{
        string target,item,force;
        object obj, who,*inv,obj2;
        int i,amount,do_force;
 
        if (!NATURE_D->vision(me))
          return notify_fail("四週烏漆媽黑的，什麼也看不到.\n");
 
        if(!arg) return notify_fail("你要給誰什麼東西﹖\n");
        arg = lower_case(arg);
 
        if (sscanf (arg,"%s %s",force,item) == 2)
          if (force == "-f") {
            if (!wizardp(me)) force = 0;
          }
          else force = 0;
 
        if (force && force == "-f") do_force = 1;
 
        if( sscanf(arg,"%s to %s",item,target)==2
        || sscanf(arg,"%s %s",target,item)==2 );
        else return notify_fail("你要給誰什麼東西﹖\n");
 
        if(!objectp(who = present(target,environment(me))) || !living(who))
                return notify_fail("這裡沒有這個人。\n");
 
        if (wizardp(me) && !wizardp(who) &&
          wizhood(me)!="(manager)" && wizhood(me) != "(admin)" && wizhood(me) != "(arch)")
        {
          return notify_fail("巫師不能給玩家東西\n");
        }
        if(sscanf(item,"%d %s",amount,item)==2) {
                if( !objectp(obj = present(item,me)) )
                        return notify_fail("你身上沒有這樣東西。\n");
     
                if(obj->query_temp("mdragon"))
      return notify_fail("魔龍裝備已分化了,你必需重新組合才能給人\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分開給人。\n");
 
                if( amount < 1 )
                        return notify_fail("東西的數量至少是一個。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() )
                        return do_give(me,obj,who,do_force);
                else {
                  obj->set_amount( (int)obj->query_amount() - amount );
                  obj2 = new(base_name(obj));
                  obj2->set_amount(amount);
                  return do_give(me,obj2,who,do_force);
                }
        }
 
        if (item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        do_give(me,inv[i],who,do_force);
                }
                write("好了.\n");
                if (userp(me)) me->save();
                if (userp(who)) who->save();
                return 1;
        }
 
        if(!objectp(obj = present(item,me)))
                return notify_fail("你身上沒有這樣東西。\n");
        return do_give(me,obj,who,do_force);
}
 
int do_give(object me,object obj,object who,int force)
{
  object        *light;
 
  int carry = sizeof(all_inventory(me));
  if( carry >= MAX_CARRY ) return notify_fail("你身上的東西太多了。\n");
  if(!obj) return 1;
if( !force && (obj->query_temp("secured") || obj->query_temp("mdragon")) )
    return notify_fail ("這東西不能給人.\n");
     
if(obj->query("clan_name")&&obj->query("clan_name")!=who->query("clan/name"))
return notify_fail("幫派東西只能給本幫派的人。\n");
  if( userp(who) && !interactive(who) )
    return notify_fail("你只能把東西送給其他玩家操縱的人物。\n");
if(obj->query_temp("focuskee")==1)
return notify_fail("此武器被真企纏住不能給人。\n");
  if( obj->move(who) ) {
    // 火把
if (obj->query("id") != "lightfire") {
    if (obj->query("had_light")) {
        obj->delete("had_light");
        obj->delete("short");
        write (sprintf ("當你把%s給人的時候，這%s%s也漸漸暗淡下來。\n",
          obj->name(),obj->query("unit"),obj->name()));
    }
}
 
    if (me->is_fighting()) me->start_busy(1);
    printf("你給%s一%s%s。\n",who->name(),obj->query("unit"),
    obj->name());
    message("vision",sprintf("%s給你一%s%s。\n",me->name(),
    obj->query("unit"),obj->name()),who );
    message("vision",sprintf("%s給%s一%s%s。\n",me->name(),who->name(),
    obj->query("unit"),obj->name()),environment(me),({me,who}) );
    if (!userp(who)) {
      who->accept_object(me,obj);
      return 1;
    }
    else {
      me->save();
      who->save();
      return 1;
    }
  }
  else return 0;
}
 
int help(object me)
{
write(@HELP
指令格式 : give <物品名稱> to <某人>
      或 : give <某人> <物品名稱>
指令說明 :
           這個指令可以讓你將某樣物品給別人，
         當然，首先你要擁有這樣物品。
其他參考 :
           get，drop
HELP
    );
    return 1;
}
