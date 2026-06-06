#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include "/open/open.h"
inherit ITEM;
int help(object);
int level=0,armor_power=0,eq=1,now_def=0;
void create()
{
   seteuid(getuid());
   set_name("影武者",({ "nija fighter","nija","fighter" }) );
   set("long",@LONG
     這是東瀛忍術超高禁術,所產生出來的忍者分身。據說早已失傳，沒想到又出現了。
     下列是你可以對他下的命令
     培養(feed)     格式 feed   <killer pill> ：使影武者成長
     命名(rename)   格式 rename <name>        ：為影武者改名
     資料(mob_data) 格式 mob_data             ：察看影武者等級與經驗值
     護具(mob_eq)   格式 mob_eq <防具>        : 用於提高影武者的護身效果
     成長到一定程度，可以使用下列命令
     護身(helpme)   格式 helpme  <自己的名字> :可提高防禦力
     背刺(mob_bak)  格式 mob_bak <敵人>       :一般時候，可以用於背刺敵人
     纏住(busy)     格式 busy    <敵人>       :戰鬥中衝出，妨礙敵人
     捨身(charge)   格式 charge               :耗損自身的等級，來回復你的精氣神
     分身(sub)      格式 sub                  :把武影者變成你的分身
                                               變成分身後可打show觀看分身指令
     說話(mob_say)  格式 mob_say <msg>        :讓影武者按照你的心意說話

LONG);
   set("unit","位");
   set("no_sell",1);
   set("no_drop",1);
   set("no_auc",1);
   set("weight",50);
   setup();
}

void init()
{
    if( this_player()==environment() )
    {
       add_action("feed_pet","feed");
       add_action("rename_pet","rename");
       add_action("mob_busy","busy");
       add_action("mob_charge","charge");
       add_action("mob_help","helpme");
       add_action("to_eq","mob_eq");
       add_action("to_say","mob_say"); 
       add_action("bit_pet","mob_bak");
       add_action("verify_pet","mob_data");
       add_action("do_sub","sub");
    }
}

int feed_pet(string arg)
{
   object obj,me=this_player();
   int expm;

   if(!arg)  return notify_fail("指令格式: feed <killer pill>\n");
   if(!(obj=present(arg,me)))
       return notify_fail("你身上沒這樣東西。\n");
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保護你，那有心思吃藥呀？\n");
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
   this_object()->set("busy_times",0);
   this_object()->set("mudsay",0);
   return 1;
}

int rename_pet(string arg)
{
   if(!arg) return notify_fail("你想把他改成什麼名字呢?\n");
   arg = trans_color(arg);
   this_object()->set_name(arg + NOR,({ "nija fighter","nija","fighter" }) );
   write("你替你的影武者取了個名字叫"+this_object()->name()+"。\n");
   return 1;
}

int to_say(string arg)
{
   int pow,helpme,t_kee,buf;
   object ob,me,target;
   string str;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   if(ob->query("mudsay")!= 0)
      return notify_fail(ob->name()+"剛才說的快累死了，再給他藥吧。\n");
   if( pow < 80 ) 
       return notify_fail(ob->name()+"還不夠強大喔,再多餵他一些殺手密藥吧。\n");
   if(!arg) return notify_fail("你想要他說什麼呢？\n");
   
   message("mud",HIG+ob->name()+HIG+"說：『"+arg+"』\n" + NOR,users());
   ob->set("mudsay",1);
   return 1;
}

int mob_help(string arg)
{
   int pow,helpme,t_kee,buf;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   helpme=ob->query("helpme");
	// 87.6.12加入
	//避免使用sub之後,影舞者的防禦力變成零
   armor_power=me->query_temp("mob_def");

   if( !arg )
       return help(me);
   if (arg == "none")
   {
    ob->set("helpme",0);  //還要使自己的防禦力下降
    me->add_temp("apply/armor",-now_def);
    return 1;
   }
   if (helpme == 1)
       return notify_fail(ob->name()+"已經在保護你了\n");
   target = present(arg, environment(me)); 
   if( target != me ) 
       return notify_fail(ob->name()+"去保護別人？真是偉大的情操\n");
   if( pow < 3 ) 
       return notify_fail(ob->name()+"還不夠強大喔,再多餵他一些殺手密藥吧。\n");
   buf=armor_power;  //取得武者的防禦力
   if( buf > 600 )
   {
    message_vision(ob->name()+HIM+"化成一道金光，佈滿你的周圍，形成超級防護層\n" + NOR,target);
    me->add_temp("apply/armor",200);
    ob->set("helpme",1);
    now_def=200;
    return 1;
   }
   if( buf > 250 )
   {
    message_vision(ob->name()+HIM+"化成一道金光，全心的吸引敵人的注意\n" + NOR,target);
    me->add_temp("apply/armor",80);
    ob->set("helpme",1);
    now_def=80;
    return 1;
   }
    if( buf > 200 )
    {
     message_vision(ob->name()+HIM+"拿起防具，全神地戒備著\n" + NOR,target);
     me->add_temp("apply/armor",60);
     ob->set("helpme",1);
     now_def=60;
     return 1;
    }
    if( buf > 150 )
    {
     message_vision(ob->name()+HIM+"全神地戒備地看著四周\n" + NOR,target);
     me->add_temp("apply/armor",40);
     ob->set("helpme",1);
     now_def=40;
     return 1;
    }
    if( buf > 100 )
    {
     message_vision(ob->name()+HIR+"戒備地看著四周\n" + NOR,target);
     me->add_temp("apply/armor",30);
     ob->set("helpme",1);
     now_def=30;
     return 1;
    }
    if( buf > 50 )
    {
     message_vision(ob->name()+HIR+"輕鬆地看著四周\n" + NOR,target);
     me->add_temp("apply/armor",20);
     ob->set("helpme",1);
     now_def=20;
    return 1;
    }
     message_vision(ob->name()+HIR+"能保護你嗎？，你還是自己小心點吧\n" + NOR,target);
     return 0;
}

int to_eq(string arg)
{
  object ob,me;
  int armor;

  me=this_player();
  seteuid(getuid());
  if( !arg ) return help(me);
  if(!(ob = present(arg,me))) return notify_fail("你身上沒這個東西！\n");
  if (ob->limit_ident(me)) 
    return notify_fail("唉呀！這物品似乎被某種封印封住了，所以影武者也不能裝備\n\n"); 
  if (ob->query("skill_type")) 
      return notify_fail("拜託，我不是說不能給武器嗎？\n\n"); 
  if (eq > 5)
      return notify_fail("拜託，你把他當豬嗎？還是倉庫呀？\n\n"); 

  if (ob->query("armor_type")) 
  {
    armor=ob->query("armor_prop/armor");
    switch(ob->query("armor_type"))
    {
      case(TYPE_CLOTH):	armor=armor*3;break;
      case(TYPE_SHIELD):armor=armor*4;break;
      case(TYPE_HEAD):
      case(TYPE_PANTS):	armor=armor*6;break;
      case(TYPE_NECK):
      case(TYPE_ARMBANDS):
      case(TYPE_WAIST):
      case(TYPE_WRISTS):
      case(TYPE_FINGER):
      case(TYPE_HANDS):
      case(TYPE_BOOTS):
      case(TYPE_LEGGINGS):
      case(TYPE_CAPE):	armor=armor*12;break;
    } 
    destruct(ob);
    eq+=1;
    armor_power=armor_power+armor;
	// 87.6.12加入
	//避免使用sub之後,影舞者的防禦力變成零
    me->set_temp("mob_def",armor_power);
    write(this_object()->name()+HIG"將防具收下來！\n" + NOR);
    return 1;                          //要防止防禦力的累積
 }
  if (ob->query("食物")) 
    return notify_fail("不會吧？食物太多是不是？\n\n"); 
  if (ob->query("液體")) 
    return notify_fail("你想讓他對敵人潑水呀？\n\n"); 
  if (ob->query("light_up"))
    return notify_fail("你看的到就夠了啦！\n\n"); 
  return notify_fail("wa ley....你到底是給什麼呀？\n\n"); 
} 
 
int mob_charge(string arg)
{
   int pow,bak_times,t_kee,buf;
   object ob,me,target;
   string str;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   if( pow < 50 ) 
     return notify_fail(ob->name()+"還不夠強大喔,再多餵他一些殺手密藥吧。\n");
   if( !arg )
   {
     write(ob->name()+HIG"收到命令後，知道他報效的時機來了。\n" + NOR);
     write(ob->name()+HIG"閉上雙眼，屏氣凝神，使得原本黝黑的身體起了一陣光芒。\n" + NOR);
     write(HIG + "瞬間閃出一陣光芒，"+me->name()+"被光芒籠罩住\n" + NOR);
     tell_object(me,"你感到你原本受損的身體，身心都完全回復了\n");
     me->set("gin",me->query("max_gin"));
     me->set("kee",me->query("max_kee"));
     me->set("sen",me->query("max_sen"));
     me->clear_condition();
     write(ob->name()+HIG"在光芒散去後，也消失的無影無蹤。\n" + NOR);
     ob->add("lv",-2);
     ob->set("exp",1);
     destruct(ob);
     me->add("monkey_lv",-2);
     me->set("monkey_exp",1);
     return 1;
   }    
   return notify_fail(ob->name()+"不會替別人捨身啦！。\n");
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
   if( target->query_temp("bit")==1)
       return notify_fail("你以為敵人很笨會上二次當嗎？\n");
   if( pow < 5 ) 
       return notify_fail(ob->name()+"還不夠強大喔,再多餵他一些殺手密藥吧。\n");
   if( bak_times > 2)
       return notify_fail(ob->name()+"很累了，再多餵他一些殺手密藥吧。\n");
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保護你，那有心思背刺呀？\n");

   message_vision(
   ""+ob->name()+"潛入房中的暗處，準備背刺$n。你摒息的看著它\n\n",me,target);
   buf=random(pow+15);
   if( buf > 15 )
   {
    if( buf > 30 )
    {
     message_vision(HIG + "$N不夠小心,被"+ob->name()+HIR+"背刺了！\n" + NOR,target);
     t_kee=target->query("max_kee")/13;
     target->add("kee",-t_kee);
     target->set_temp("bit",1);
     ob->add("bak_times",1);
     return 1;
    }
    if( buf > 60 )
    {
     message_vision(HIG + "$N毫無警覺,被"+ob->name()+HIR+"狠狠地背刺了！\n" + NOR,target);
     t_kee=target->query("max_kee")/10;
     target->add("kee",-t_kee);
     target->set_temp("bit",1);
     ob->add("bak_times",1);
     return 1;
    }
    if( buf > 90 )
    {
     message_vision(HIG + ""+ob->name()+HIR+"狠狠地使出雙重背刺！！$N受創很深！\n" + NOR,target);
     t_kee=target->query("max_kee")/5;
     target->add("kee",-t_kee);
     target->set_temp("bit",1);
     ob->add("bak_times",1);
     return 1;
    }
    message_vision(HIG + "$N一個不留意,被"+ob->name()+HIR+"背刺了！\n" + NOR,target);
    t_kee=target->query("max_kee")/20;
    target->add("kee",-t_kee);
    target->set_temp("bit",1);
    ob->add("bak_times",1);
    return 1;
   }
   else
   {
    message_vision(HIC + "$N急急忙忙往後跳開, 被"+ob->name()+HIC+"嚇出了一深冷汗。\n" + NOR,target);
    target->add("sen",-5);
    ob->add("bak_times",1);
    return 1;
   }
}

int mob_busy(string arg)
{
   int pow,busy_times,t_kee,buf;
   object ob,me,target;
   string str;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   busy_times=ob->query("busy_times");

   if( !arg )
       return notify_fail("你想叫"+ob->name()+"去纏住誰﹖\n");
   target = present(arg, environment(me)); 
   if( target->query("no_kill") ) 
       return notify_fail("這傢伙你不能動就是不能動。\n");
   if( !wizardp(me) && environment(me)->query("no_fight") )
       return notify_fail("這裡禁止戰鬥。\n");
   if( target->is_busy() )
       return notify_fail("敵人已挨打中，你還要做什呀！\n");
   if( !target->is_character() || target->is_corpse() )
       return notify_fail("看清楚點,它並不是活物。\n");
   if( target == me ) 
       return notify_fail(ob->name()+"本來就纏著你，你還要他多膩你呀？。\n");
   if( pow < 30 ) 
       return notify_fail(ob->name()+"還不夠強大喔,再多餵他一些殺手密藥吧。\n");
   if( busy_times > 1)
       return notify_fail(ob->name()+HIG"很累了，再多餵他一些殺手密藥吧。\n" + NOR);
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保護你，那有心思去纏住敵人呀？\n");

   if ( me->is_fighting(target) || me->is_killing(target) )
   {
   message_vision(ob->name()+"不顧生命危險，在戰鬥中衝了出去，想設法纏住$n。\n",target);
   buf=random(pow+20);
   if( buf > 90 )
   {
     message_vision(HIG + "$N被"+ob->name()+HIR+"奮不顧身的打法，逼的根本沒有辦法對你進攻！\n" + NOR,target);
     target->start_busy(2);
     t_kee=target->query("max_kee")/15;
     target->add("kee",-t_kee);
     ob->add("busy_times",1);
     return 1;
   }
   if( buf > 70 )
   {
     message_vision(HIG + "$N被"+ob->name()+HIR+"的連續攻擊纏住了\n" + NOR,target);
     target->start_busy(2);
     t_kee=target->query("max_kee")/15;
     target->add("kee",-t_kee);
     ob->add("busy_times",1);
     return 1;
    }
    if( buf > 50 )
    {
     message_vision(HIG + ""+ob->name()+HIR+"連射數道飛刀，逼的$N有點手忙腳亂\n" + NOR,target);
     target->start_busy(1);
     t_kee=target->query("max_kee")/20;
     target->add("kee",-t_kee);
     ob->add("busy_times",1);
     return 1;
    }
    if (buf > 20)
    {
     message_vision(HIG + ""+ob->name()+HIR+"衝了出去，令$N身形一頓\n" + NOR,target);
     target->start_busy(1);
     ob->add("busy_times",1);
     return 1;
    }
    message_vision(HIG + "$N被衝出來的"+ob->name()+HIR+"撞到了，但無傷大雅\n" + NOR,target);
    t_kee=target->query("max_kee")/20;
    target->add("kee",-t_kee);
    ob->add("busy_times",1);
    return 1;
   }
   return notify_fail("神經病，不在戰鬥中，你纏心酸的呀！\n");
}

int verify_pet(string str)
{
  int lv,expm,armor;
  object obj=this_object();

	// 87.6.12加入
	//避免使用sub之後,影舞者的防禦力變成零
   armor_power=this_player()->query_temp("mob_def");

  lv =  (int)obj->query("lv");
  expm = (int)obj->query("exp");
  write(obj->name()+"      目前等級   :  "+lv+"\n\n");
  write(obj->name()+"      目前經驗值 :  "+expm+"\n\n");
  write(obj->name()+"      目前防禦力 :  "+armor_power+"\n\n");
  return 1;
}


//add by Leei
int do_sub(string str)
{
   int pow;
   object ob,me,sub;

   me = this_player();
   ob = this_object();
   pow = ob->query("lv");
   if( !pow || pow < 80 )
     return notify_fail(ob->name()+"不夠強,再多餵他一些殺手密藥吧。\n");
   if(this_object()->query("helpme")==1)
       return notify_fail("他在保護你，還想出分身，又不是妖怪\n");
   if ( me->query("force") < 100 )
     return notify_fail("你的內力不夠。\n");
   if ( !me->is_fighting() )
     return notify_fail("在戰鬥中才能呼叫分身。\n");
   if ( me->query_temp("sub","USED") )
    return notify_fail("你得武影者沒有歸位，請離線後再進入。\n");
   if( !str )
   {
    message_vision(HIC + "$N向$N的 " + NOR + "$n " + HIC + "求救,突然間$N的 " + NOR + "$n " + HIC + "變成人加入這場戰鬥。\n" + NOR,me,ob);
    me->add("force",-100);
    me->set_temp("sub","USED");
    sub=new("/open/killer/obj/two.c");
    sub->set("sub_id",""+me->query("id")+"");
    sub->set("old_name",""+ob->name()+"");
    sub->move( environment(me) );
    sub->invocation(me);
    destruct(ob);
   }
   return 1;
}


int query_autoload ()
{
  if (this_player()->query("quest/rain") == 1)
    return 1;
  return 0;
}  
int help(object me)
{
  write (@HELP
指令     : to_eq ,helpme
指令說明 :
       to_eq: 給與你的影武者防具，但是不能給武器，因為影武者的能力有限
              給他的防具，他並不是用來裝備，而是拿來抵擋對手
              一位影武者可拿的防具，不可超過5項，防禦力越高提昇的效果越好
              當然，離線後他的防具也會消失,如果影武者的防禦力低於50點的話,
           會因為自身難保,而不能保護你
      helpme: 讓影武者專心的抵擋攻擊，可在一般時候就使用護身，不需等戰鬥才用
              護身中的影武者無法進行背刺，纏住，培養，但是仍可以捨身。
 helpme none: 可以取消護身的效果。
HELP); 
  return 1;
}
