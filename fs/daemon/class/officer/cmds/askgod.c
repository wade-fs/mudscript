//  made by ccat
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

object aim;
int report=0;
int main(object me, string arg)
{
object obj,objj;
int skill,i,kee,kee2,exp1,exp2;
  string str,name;
  seteuid(getuid()); 
  if( me->query("sen") < 30 ) return notify_fail("你的神不足.\n");
  if( me->query("force") < 50 ) return notify_fail("你的內力不足.\n");
  if(me->is_fighting())  return notify_fail("戰鬥中無法占卜。\n");
if((int)me->query_temp("godd",1)) return notify_fail("神正在忙啦~~\n");

  if( !arg )
    return notify_fail("指令格式﹕cmd askgod <id>\n");
  if(arg=="sa" || arg=="degu sa") 
    return notify_fail("想用占卜對付我？？門都沒有！！");

  arg = lower_case(arg);

  if( !objectp(obj = present(arg, environment(me))) )
    return notify_fail("你想對誰占卜?\n");
  if( obj->query("no_askgod") )
        return notify_fail("這傢夥你不能動就是不能動。\n");


  if( !obj->is_character() || obj->is_corpse() || obj->query_temp("netdead") )
    return notify_fail("那並不是活物。\n");

  skill = me->query_skill("security",1);
  skill = random(skill);
  me->receive_damage("sen",30,me);
  me->add("force",-50);
  
  exp1 = me->query("combat_exp");
  exp2 = obj->query("combat_exp");
  if( exp1 > exp2) exp1 = exp2*3; 
  if( exp1 < exp2) exp1 = exp1*3;
  if(  random(exp1) > random(exp2) )
  {
     aim = obj;
  }else  aim = me;
  
  name = aim->query("name");
  i = random(9);
  switch(i)
  {
    case 0:
    case 1:
    case 2:
      report=1;
      kee = aim->query("max_kee");
      kee2 = aim->query("kee");  
      if( skill < 15)
      {
          str="突然間 "+name+" 開始上吐下瀉.\n"+
              "$N搖頭嘆道:唉!! 以後吃東西要小心";
          kee = kee*0.2; 
       }else if( skill < 25)
       {
          str="$N說: 有了..."+name+" 今天不宜運\功\.\n"+
              "話才剛停,只見"+name+"臉色一陣青一陣白,似乎內息走插了";
          kee = kee*0.3;
       }else if( skill < 45)
       {
          str="$N說: 算到了!!"+name+" 今天不宜到處遊蕩.\n"+
              "突然間平地一聲雷起,一道閃電擊中"+name+"\n"+
              "$N嘆道: 唉...說的太遲了";
          kee = kee*0.4;
       }else if( skill < 80)
       {
          str="突然$N 大叫: 快請大夫!!\n"+
              name+" 嘴巴乎然一歪,顯然是中風了";
          kee = kee*0.5;
       }else{
          str="$N說: 唉!!... "+name+"顯然活不過今晚,\n"+
              "語音剛落,"+name+"已經不行了";
          kee = kee*0.6;
       }
       if( kee > kee2)
          kee = (int)kee2*0.7;
       aim->receive_damage("kee",kee,me);
       break;
    case 3:
    case 4:
    case 5:
       if( skill < 30)
       {  
          str="$N說: 算到了...今天某處會發生火災!!\n話才說完"+
              name+"身上突然燃起熊熊烈火,果真應驗了";
          aim->apply_condition("burn",(int)skill/6);
       }else if( skill<60 ){
          str="$N對"+name+"搖搖指頭說:這樣不行喔...\n"+
              "突然"+name+"臉色發紅,雙手掩住下部,看似發春了";
          aim->apply_condition("spring",(int)skill/10);
       }else{
          str="途然大地分裂,一陣黑火從地底冒出,燃燒著 "+name+
              "\n $N 真是做惡太多了";
          aim->apply_condition("hellfire",(int)skill/10);
       }
       break;
    case 6:
    case 7:
       str=name+" 途然像狗一樣趴在地上,原來是撿到了錢";
       objj=new("/obj/money/silver");
       objj->move(aim);
       objj->add_amount(skill);
       break;
    case 8:
         str="$N 說: 算到了...看樣子明天是晴天";
  }
  message_vision("$N\擺\起神案,對著$n開始占卜...\n"+
                 "只見$N手搖著鈴鐺,嘴裡喃喃自語.\n"+
                 str+"!!\n",me,obj);
	me->set_temp("godd",11);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me :), 3);
  return 1;
}

void remove_effect (object me)
{
 if( report)
    COMBAT_D->report_status(aim, 0);
me->set_temp("godd",0);

}
int help(object me)
{
  write(@HELP
指令格式 : cmd askgod <人物>
指令說明 : 
           這個指令讓你對某人占卜,但無法預知是福是禍.
           治安策越高,造成的影響越大.
HELP
    );
    return 1;
}
 
