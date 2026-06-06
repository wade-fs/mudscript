#include <ansi.h>
inherit ITEM;

int level=0;
void create()
{
   seteuid(getuid());
   set_name("忍者猴",({ "nija monkey","nija","monkey" }) );
   set("long",@LONG
       這是一隻忍者猴子,你可以飼養(feed)它,讓他長大,還可以幫他改名字(rename),
       等到它長的夠大了,便可以放他出去背刺敵人(mob_bak),你可用verify來看他長的
       程度到多少。但是，因為他是活物，所以必須餵他，他才會恢復原有的力量

LONG);
   set("unit","條");
   set("no_sell",1);
   set("no_drop",1);
   set("weight",50);
   setup();
}

void init()
{
    if( this_player()==environment() )
    {
       add_action("feed_pet","feed");
       add_action("rename_pet","rename");
       add_action("bit_pet","mob_bak");
       add_action("verify_pet","verify");
    }
}

int feed_pet(string arg)
{
   object obj,me=this_player();
   int expm;

   if(!arg)  return notify_fail("指令格式: feed <殺手密藥>\n");
   if(!(obj=present(arg,me)))
       return notify_fail("你身上沒這樣東西。\n");
   if(obj->query("id") != "killer pill")
       return notify_fail("你只能餵它殺手密藥。\n");
   message_vision("$N餵了"+this_object()->name()+"一顆殺手密藥。\n",me);
   if (!me->query("monkey_exp"))
   { 
      me->set("monkey_exp",1); 
      me->set("monkey_lv",1);
   }    
   expm=random(20);
   me->add("monkey_exp",expm);
   expm=me->query("monkey_exp");
   if (expm >= 100)  //升級
   {
    level =me->query("monkey_lv");
     level += 1;
     if (level > 100)
       level=100;
     me->set("monkey_lv",level);
     me->set("monkey_exp",1);
     expm=0;
   }
   obj->add_amount(-1);
   this_object()->set("lv",me->query("monkey_lv"));
   this_object()->set("exp",me->query("monkey_exp"));
   this_object()->set("bak_times",0);
   return 1;
}

int rename_pet(string arg)
{
   if(!arg) return notify_fail("你想把他改成什麼名字呢?\n");
   arg = trans_color(arg);
   this_object()->set_name(arg + NOR,({ "nija monkey","nija","monkey" }) );
   write("你替你的寵物取了個名字叫"+this_object()->name()+"。\n");
   return 1;
}

int bit_pet(string arg)
{
   int pow,bak_times,t_kee,buf;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   bak_times=ob->query("bak_times");
   if( !arg )
       return notify_fail("你想叫"+ob->name()+"去背刺誰﹖\n");
   target = present(arg, environment(me)); 
   if( target->query("no_kill") ) 
       return notify_fail("這傢伙你不能動就是不能動。\n");
   if( !wizardp(me) && environment(me)->query("no_fight") )
       return notify_fail("這裡禁止戰鬥。\n");
   if( !target->is_character() || target->is_corpse() )
       return notify_fail("看清楚點,它並不是活物。\n");
   if( target == me ) 
       return notify_fail(ob->name()+"看起來並不想背刺你。\n");
   if( pow < 5 ) 
       return notify_fail(ob->name()+"還不夠大喔,再多餵他一些殺手密藥吧。\n");
   if( bak_times > 2)
       return notify_fail(ob->name()+"很累了，再多餵他一些殺手密藥吧。\n");

   message_vision(
   ""+ob->name()+"潛入房中的暗處，準備背刺$n。你摒息的看著它\n\n",me,target);
   buf=random(pow);
   if( buf > 15 )
   {
    if( buf > 30 )
    {
     message_vision(HIG"$N毫無警覺,被"+ob->name()+HIR+"背刺了！\n" NOR,target);
     t_kee=target->query("max_kee")/13;
     target->add("kee",-t_kee);
     ob->add("bak_times",1);
     return 1;
    }
    if( buf > 60 )
    {
     message_vision(HIG"$N毫無警覺,被"+ob->name()+HIR+"狠狠地背刺了！\n" NOR,target);
     t_kee=target->query("max_kee")/10;
     target->add("kee",-t_kee);
     ob->add("bak_times",1);
     return 1;
    }
    if( buf > 90 )
    {
     message_vision(HIG""+ob->name()+HIR+"狠狠地使出雙重背刺！！$N受創很深！\n" NOR,target);
     t_kee=target->query("max_kee")/5;
     target->add("kee",-t_kee);
     ob->add("bak_times",1);
     return 1;
    }
    message_vision(HIG"$N一個不留意,被"+ob->name()+HIR+"背刺了！\n" NOR,target);
    t_kee=target->query("max_kee")/20;
    target->add("kee",-t_kee);
    ob->add("bak_times",1);
    return 1;
   }
   else
   {
    message_vision(HIC"$N急急忙忙往後跳開, 被"+ob->name()+HIC+"嚇出了一深冷汗。\n" NOR,target);
    target->add("sen",-5);
    ob->add("bak_times",1);
    return 1;
   }
}
  
int verify_pet(string str)
{
  int lv,expm;
  object obj=this_object();

  lv =  (int)obj->query("lv");
  expm = (int)obj->query("exp");
  write(obj->name()+"      目前等級   :  "+lv+"\n\n");
  write(obj->name()+"      目前經驗值 :  "+expm+"\n\n");
  return 1;
}

int query_autoload ()
{
  if (this_player()->query("quest/rain") == 1)
    return 1;
  return 0;
}
