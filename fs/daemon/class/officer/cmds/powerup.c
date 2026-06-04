// powerup.c
//補上剛加入官員時 關係不足的判斷 by blazakira 2011/8/22

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

string *report = ({
  "職政以後﹐政績良好﹐深得民心。\n",
  "為官清正﹐表現極佳。\n",
  "才學淵博﹐處事有條有理。\n",
});

string *down = ({
  "錯失一賢﹐國未必亡﹐用錯一人﹐貽禍萬年﹐請皇上三思。\n",
  "微臣認為﹐此人雖佳﹐但尚年輕﹐經驗未足﹐皇上宜三思。\n",
  "微臣認為此人尚年輕﹐不足以擔當大任。\n",
  "據微臣所知﹐此人並非如傳聞般好﹐請皇上三思。\n",
});

int main(object me, string arg)
{
  object ob;
  string msg;
  int th;
  int i,power,count=0;
  int too,max_power;
  string *name;

  if(!arg||sscanf(arg,"by %s",arg)!=1)
    return notify_fail("格式﹕powerup by <officer>\n");

  if(!objectp(ob = present(arg, environment(me))) )
    return notify_fail("這裡沒有這個人。\n");

  if( me->query("sen") < 50)
    return notify_fail("你的神不足。\n");
  if(!living(ob)||ob->query("class")!="officer")
    return notify_fail("你只能請朝廷官員幫你提升權力。\n");

  if(userp(ob)&&ob->query("no_power")!=1) return notify_fail("他不願幫你。\n");
  if(!me->query("relation")) return notify_fail("你與他的關係不夠好。\n");
  name=keys(me->query("relation"));
  for(i=0;i<sizeof(name);i++)
    count=count+me->query("relation/"+name[i]+"/value")*me->query("relation/"+name[i]+"/power");
  count+count/2;
  power=count/200+me->query("office_exp")/20000;
  max_power = me->query("max_officer_power");
  if(power==max_power || max_power > 50000)
    return notify_fail("你的權力已達上限。\n");
  me->add("sen",-50);
  message_vision(CYN + "$N說道﹕$n大人﹐能否為下官在皇上面前美言幾句 ?\n",me,ob);
  if(me->query("relation/"+ob->query("id")+"/value")+25<ob->query("officer_power")/2)
  {
    message_vision("$n臉色上似乎有難言之隱。\n" + NOR,me,ob);
    return 1;
  }
  if(ob->query("officer_power")<50)
  {
    message_vision("$n說道﹕下官官職卑微﹐恐怕幫不了你。\n" + NOR,me,ob);
    return 1;
  }
  message_vision(CYN + "$n說道﹕沒問題﹐包在我身上。\n" + NOR,me,ob);
  msg=HIR+ob->name()+"上奏天子﹕\n";
  msg+=HIY+me->query("officer_class")+me->name()+report[random(sizeof(report))];
  msg+=ob->name()+"﹕";
  msg+="微臣懇請皇上為"+me->name()+"升職﹐以盡用其人﹐造福萬民。\n";
  for(too=0;too<sizeof(name);too++)
    if(me->query("relation/"+name[too]+"/value")>0&&name[too]!=ob->query("id"))
      msg+=HIG+me->query("relation/"+name[too]+"/name")+"﹕微臣也認為"+me->name()+"應受重用。\n";
  for(i=0;i<sizeof(name);i++)
    if(me->query("relation/"+name[i]+"/value")<0)
    {
      th=me->query("relation/"+name[i]+"/value")*(-1)/10;
      if(th>3) th=3;
      msg+=HIM+me->query("relation/"+name[i]+"/name");
      msg+="﹕"+down[th];
    }
  if(me->query("max_officer_power")<power)
    msg+=HIC+"皇上﹕"+me->name()+report[random(sizeof(report))]+"      "+me->name()+"官升一品。\n";
  else
    msg+=HIC+"皇上﹕朕素為此人為官辦事不力﹐非國之棟樑也。\n      "+me->name()+"官降一品。\n";

//  message("system",msg+NOR,users());
  message_vision(msg+NOR,me);
  me->set("officer_power",power);
  me->set("max_officer_power",power);
  return 1;
}

int help(object me)
{
   write( @HELP
指令格式﹕powerup by <officer>

這個指令讓你可以由藉由其他大臣幫你提升權力。
HELP
  );
  return 1;
}
