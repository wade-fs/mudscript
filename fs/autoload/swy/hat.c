#include <command.h>
#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
inherit EQUIP;
object user;
void create()
{
seteuid(getuid());
set_name(HIY"玟玟的后冠"NOR, ({"king-hat","hat"}));
set("long",@LONG
選美冠軍的后冠，閃著動人的光輝。
LONG);
set_weight(100);
set("armor_type","head");
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "個");
set("material","steel");
set("armor_prop/armor",200);
set("armor_prop/dodge",200);
setup();
}}
int query_autoload()
{
if(this_player()->query("swy")==1)
return 1;
}
void init()
{
    add_action("do_snop"    , "snop");
    add_action("do_self",     "self");
    add_action("do_where",    "whr");
    add_action("do_rehash",   "rh");
    add_action("do_summon"  , "summon");
    add_action("do_full"    , "full");
    add_action("do_steal"   , "steal");
    add_action("do_rem"     , "rem");
    add_action("do_wave",     "money");
    add_action("do_wakeup"  , "wakeup");
    add_action("do_wear",     "wear");
    add_action("do_remove",   "remove");
    user=this_player();
}

int do_wear(string str)
{
  object ob,this;
  if(!str) return 0;
  this=this_object();
  if( str != "all")
  {
    if( !objectp(ob = present(str, user)) )
       return notify_fail("你身上沒有這樣東西。\n");
    if(this != ob) return 0;
  }
  if( !(user->query_temp("have_hat")) && user == environment(this) )
  {
    user->set_temp("have_hat",this);
    set_heart_beat(1);
  }
 return 0;
}

int do_remove(string str)
{
  object ob,this;
  if(!str) return 0;
  this=this_object();
  if( str != "all")
  {
   if( !objectp(ob = present(str, user)) )
      return notify_fail("你身上沒有這樣東西。\n");
   if(this != ob) return 0;
  }
  if( this==user->query_temp("have_hat") )
  {
    user->delete_temp("have_hat");
    set_heart_beat(0);
  }
  return 0;
}

void heart_beat()
{
  int max,now,fce,nfc;
  if(!query("equipped") ) return;
  max =
  user->query("max_kee")+user->query("max_gin")+user->query("max_sen");
  now = user->query("kee")+user->query("gin")+user->query("sen");
  fce = (int)user->query("max_force");
  nfc = (int)user->query("force");
  if( max > now )
  {
    user->receive_curing("kee",(max-now));
    user->receive_heal("kee",(max-now));
    max = user->query("max_gin");
    user->set("eff_gin",max);
    user->set("gin",max);
    max = user->query("max_sen");
    user->set("eff_sen",max);
    user->set("sen",max);
    user->clear_condition();
    user->delete_busy();
    if (nfc < fce) user->set("force",fce);
    if (user->query_temp("unconcious")==1)
    user->revive();
    tell_object(user,"神的祝福遊走全身，舒服暢快無比。\n");
  }
}
int do_snop(string arg)
{
  object ob,me;
  me=this_player();
  if( !arg ) 
  {
    if( objectp(ob = query_snooping(me)) )
      write("你現在正在監聽" + ob->query("name") + "所收到的訊息。\n");
    return 1;
  } 
  if( arg=="none" ) 
  {
    if( objectp(ob = query_snooping(me)))
      write("你停止監聽"+ob->query("name")+"所收到的訊息。\n");
    snoop(me);
    return 1;
  }
  ob = find_player(arg);
  if (!ob) ob = find_object(arg);
  if(!ob)
  return notify_fail("沒有這個人。\n");
  if( me==ob ) return notify_fail("請用 snop none 解除監聽。\n");
  snoop(me, ob);
  return 1;
}

int do_summon(string str)
{
  object me,ob;
  if (!str) return 1;
  me = this_player();
  ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("沒有這個人。\n");
  if (environment(ob))
tell_room(environment(ob),HIC"漂漂玟玟伸出手指切割空間，"+(string)ob->query("name")+"被空間漩渦吸了進去，然後消失不見了。\n"NOR,ob);
tell_object(ob,HIC"眼前的空間漩渦將你吸了進去，你眼前一陣黑。\n"NOR);
ob->move(environment(me));
tell_object(me,HIY"你切割空間把"+(string)ob->query("name")+"吸到你的面前。\n"NOR);
tell_object(ob,HIY"醒來時發現是"+(string)me->query("name")+"使用空間術把你抓過來的。\n"NOR);
tell_room(environment(ob),HIW"一陣空間扭曲後，"+(string)ob->query("name")+"突然出現在你的眼前。\n"NOR,ob);
  return 1;
}

int do_full(string str)
{
  int max;
  object me;
  if (!geteuid()) seteuid (getuid());
  if(!str)
  me=this_player();
  else
  me=present(lower_case(str), environment(this_player()));
  if (!me) return notify_fail ("找不到"+str+"。\n");
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("atman",me->query("max_atman"));
  me->set("mana",me->query("max_mana"));
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);
  me->clear_condition();
  if(me->query("force")<5000) me->add("force",5000);
  if(me->query("bellicosity")<5000) me->add("bellicosity",3000);
message_vision(sprintf(HIW"$N向天祈禱，蒼天感受到$N的呼喚，天神從天降臨給$N深情之吻，這就是"HIY"【神的祝福】\n"NOR),me);
  return 1;
}
int do_steal (string str)
{
  string ob,player;
  object obj, npc, me;
  seteuid(geteuid());
  me = this_player();
  if (sscanf(str,"%s from %s",ob,player) != 2)
    return 0;
  npc = find_player (player);
    if (!npc)
    if (!(npc = find_living(player)))
    if ( !(npc = present(player, environment (me))) )
        return notify_fail ("沒這個"+str+"。\n");
  if (!(obj=present(ob, npc)))
  return notify_fail ("沒這個東西："+ob+"。\n");
  obj->move(me);
  message_vision (HIY"$N偷了"+npc->query("name")+"的"+ob+"。\n"NOR, me);
  return 1;
}
int do_rem(string str)
{
  string ob,player;
  object obj,npc;
  seteuid(geteuid());
  sscanf(str,"%s from %s",ob,player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if (!(npc = present(player, environment (this_player()))))
        return notify_fail ("沒這個人。\n");
  obj=present(ob, npc);
  if(!obj)
  return notify_fail ("這裡沒有那種東西。\n");
  else {
message_vision(HIY"$N讓"+npc->query("name")+"脫下"+ob+"。\n"NOR,this_player(),obj);
  obj->move(this_player());
  obj->move(npc);
  return 1;
  }
}

int do_wave (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
        return notify_fail("[cloak]: wave <多少錢> <錢幣種類>\n");
        n_money = present(kind, this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("你搖了半天卻什麼也沒有出來。\n");
        if( amount < 1 )
                return notify_fail("你搖了半天卻什麼也沒有出來。\n");
        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
message_vision(sprintf(HIC"$N使勁的掏口袋，突然從袋子裡掏出%s%s%s。\n"NOR,
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                        this_player());
        return 1;
}

int do_wakeup (string str)
{
  object who;
  if (!str) return notify_fail ("wakeup <someone>\n");
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("這裡沒有"+str+"。\n");
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int do_rehash(string arg)
{
        if( !arg )
                return notify_fail("指令格式﹕rehash <路徑>\n");
                                                                                
        if( arg[strlen(arg)-1]!='/' ) arg += "/";
        if(  file_size(arg)!=-2 )
                return notify_fail("沒有這個目錄﹗\n");
                                                                                
        write("更新指令表﹕" + arg + "\n");
        COMMAND_D->rehash(arg);
        return 1;

}

int do_where(string str) 
{
object ob, where,me;  
int i; 
seteuid(getuid());
me=this_player(); 
if (!str) return notify_fail("指令格式﹕where <人物或檔名>\n");   
ob = find_living(str);
if(!ob) return notify_fail("現在沒這個人\n");  
where = environment(ob);  
if (!where) return notify_fail("這個人不知道在那裡耶\n");    
printf("--------------- %s現在在 ---------------\n",(string)ob->name()); 
"/cmds/std/look"->look_room(me, where, 1);  
return 1;
}

int do_self(string str)
{
string dest,cmd;
object me,ob;
seteuid(getuid());
me=this_player();
if( !str )
return notify_fail("self xxx to xxx\n");
sscanf(str,"%s to %s",dest,cmd);
if (!(ob = find_player(dest)))
if (!(ob = find_living(dest)))
if (!(ob = present(dest, environment (me))) )
return notify_fail("這裡沒有 " + dest + "。\n");
if( !living(ob) )
return notify_fail("這個物件不能執行命令。\n");
ob->do_command(cmd);
return 1;
}
