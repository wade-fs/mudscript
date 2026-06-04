//暫稱魅力術 使用道具蜃珠(暫稱)在呼叫出來的npc身上? 玩家持有? 或者作為解迷道具? by blazakira 2010/10/14
//暫定 不能練 起頭由dancer的某位長老 或掌門給予lv1的起始之後 才能觸發其他門派首領的協力事件
/*
魚缸@台北 說 (下午 05:51):
new npc 然後  COMBAT_D->do_attack()看要幾次
魚缸@台北 說 (下午 05:51):
然後馬上 destruct
魚缸@台北 說 (下午 05:51):
參考連擊的部份
npc群 直接抓既有的

魔女洋子(建彰： 說 (下午 09:05):
目前構想為 第一階段 輔助型的門派首領 第二階段 攻擊型的門派首領 第三階段 quest
中相當於boss級的 例如不常出現的段譽 延慶太子之類的
得第一階段取滿 才開放第二階段
兩階段都解完畢之後
才開放第三階段

我來過,我活過,我戰鬥過,我存在過
『敬君一杯酒，送君一身傷』,段家或是儒門
『送君酒一杯。勸君赴黃泉』 某個毒教長老

*/

#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun,funlv;
int i,j,k,per;
int conjure (object me, object target)
{
  string msg,msg2,npcs;
  object *enemy,mob;

  fun=me->query("spells/bewitching/level");
//  funlv=16;
  funlv=me->query("env/bewitching/"); //測試用 實際上需根據解謎狀況來設協力對象
  if (funlv >17) { funlv=random(18); } //測試用 實際上需根據解謎狀況來設協力對象
//  j=2; //有些門派的連擊技次數相當多 所以暫定COMBAT_D->do_attack攻擊兩次
  if (me->query_per()<20) { per=0; }
  else { per=(me->query_per()-20)/5; } //dancer招收標準為容貌25以上
  j=(int)(per+1); //j=(25-20)/5+1~(35-20)/5+1=2~4
//  if (!me->query("spells/bewitching/level")) return 0; //沒學就不要用！
  if(!wizardp(me))
   return notify_fail("這法術目前尚在測試中。\n");
  if(!me->is_fighting())
   return notify_fail("這法術只能對戰鬥中的對手使用。\n");
//  if(me->query("class")!="dancer")
//    return notify_fail("這法術只有舞者能用。\n");
/*        if(me->query("combat_exp") < 1500000)
        return notify_fail("實戰經驗不足是施展不出來的!!\n");

        if(me->query("allow_fdragon")!=1) //需改為專屬quest的mark
        return notify_fail("偷學的不能使用喔\n");
*/
  if(me->query("sen") < 600 || me->query("gin") < 500 || me->query("force") < 1000 || me->query("atman") < 1500)
    return notify_fail("你的身心狀態不好喔。\n");
  if(me->query_temp("bewitching")==1)
    return notify_fail("你正在施法中。\n");
/*
路過的xx 加入戰局
風塵僕僕
助一臂之力
*/
  me->add("sen", -400);
  me->add("gin", -400);
  me->add("force", -500);
  me->add("atman", -1200);
  me->receive_damage("sen", 100);

  switch(funlv) //此參數暫定為funlv 與fun_lv per npc_exp 有關連(暫定 作為請求協助的npc群的級別 採隨機 且隨fun 愈高 則協助的npc愈強力
  {
    case 0:
      npcs ="/open/dancer/npc/master_yua.c";
      msg=BLINK+HIM + "$N說﹕乖徒兒，為師來助$n一臂之力。\n" + NOR;
      //msg2=;
      break;
    case 1:
      npcs ="/open/doctor/npc/master_tor.c";
      msg=BLINK+HIW + "$N說﹕老夫一把老骨頭了，禁不住$n這女娃兒刺激刺激。\n" + NOR;
      //msg2=;
      break;
    case 2:
      npcs ="/daemon/class/taoist/master_lu.c";
      msg=BLINK+HIW + "$N說﹕老夫一把老骨頭了，禁不住$n這女娃兒刺激刺激。\n" + NOR;
      //msg2=;
      break;
    case 3:
      npcs ="/daemon/class/scholar/master_duan.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      //msg2=;
      break;
    case 4:
      npcs ="/daemon/class/scholar/master_sue.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕找在下有事嗎？\n" + NOR; //文士的語氣 朝宜調琴，暮宜鼓瑟；舊雨適至，新雨初來。
      msg2=BLINK+"$N"+BLINK+HIY + "說﹕\n" + NOR; //吟詩而去 藝花邀蝶，栽松邀風，矚水邀萍，築臺邀月，種蕉邀雨，植柳邀蟬
      break;
    case 5:
      npcs ="/open/poison/npc/masterl.c";
      msg=BLINK+HIR + "$N說﹕老娘就是看不慣$n這女孩兒被人欺負。\n" + NOR;
      //msg2=;
      break;
    case 6:
      npcs ="/daemon/class/bandit/master_du.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      msg2=BLINK+"$N"+BLINK+HIY + "說﹕別吵，山寨那邊還有一件大買賣等著老子勒，沒空跟$N瞎攪和。\n" + NOR;
      break;
    case 7:
      npcs ="/daemon/class/officer/master_chen.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      //msg2=;
      break;
    case 8:
      npcs ="/daemon/class/killer/master_yar.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      //msg2=;
      break;
    case 9:
      npcs ="/daemon/class/blademan/master_ba.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      //msg2=;
      break;
    case 10:
      npcs ="/daemon/class/beggar/master_su.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕喲，有生意上門了是嗎。\n" + NOR;
      msg2=BLINK+"$N"+BLINK+HIY + "說﹕嘖，沒賺頭買賣別找老丐。\n" + NOR;
      break;
    case 11:
      npcs ="/daemon/class/swordsman/master.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      //msg2=;
      break;
    case 12:
//      npcs ="/open/marksman/npc/master_t.c";
      npcs ="/u/b/blazakira/fix/master_t.c";
      msg=BLINK+HIW + "$N說﹕老夫一把老骨頭了，禁不住$n這女娃兒刺激刺激。\n" + NOR;
      //msg2=;
      break;
    case 13:
      npcs ="/daemon/class/blademan/master_mou.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      //msg2=;
      break;
    case 14:
      npcs ="/daemon/class/fighter/master_jen.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕哇哈哈，果然跟$N這女娃有意思，就算是獅子搏兔也會盡全力，讓有瀧山奇俠之稱的俺來助$N一臂之力吧。看招！\n" + NOR;
      msg2=BLINK+"$N"+BLINK+HIY + "說﹕俺去了！\n" + NOR;
      break;
    case 15:
      npcs ="/daemon/class/fighter/master_liu.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕大叔我只是打醬油路過的…\n" + NOR;
      //msg2=;
      break;
    case 16:
      npcs ="/open/prayer/npc/pope.c";
      msg=BLINK+HIW + "$N說﹕本皇\n" + NOR;
      //msg2=;
      break;
    case 17:
      npcs ="/open/gsword/npc1/bloodking.c";
      msg=BLINK+"$N"+BLINK+HIY + "說﹕老夫十二恨天下無敵啦。\n" + NOR;
      msg2=BLINK+"$N"+BLINK+HIY + "說﹕老夫去找逍遙子的麻煩啦。\n" + NOR;
      break;
//    case 18:
//      npcs ="/daemon/class/bonze/master.c"; //少林未完成
//      msg=;
//      msg2=;
//      break;
  }

  seteuid(getuid());
  mob=new(npcs);
  mob->move(environment(me)); //me 為施法者

  enemy=me->query_enemy(); //將變數enemy指向施法者的敵人
  i=random(sizeof(enemy)); //為施法者敵人的數量
//       if(  ) //需改為其他判斷式 
//       {
  if ( enemy[i] && living(enemy[i]) ) {
    if ( mob->query("name") != "李廣" ) {
      mob->do_command("wield all");
      mob->do_command("exert sun-finger"); //duan專用
      mob->do_command("wield finger"); //duan專用
    }
	else {
      mob->set_temp("quest/dancer/bewitching","ok"); //在李廣身上做mark來關閉per
      mob->accept_kill(enemy[i]); //意即 mob->xxx xxx可為該mob所有的函數名稱 可參考天道靈鷹中的法術與npc的關係
    }
    mob->fight_ob(enemy[i]);
  }
  mob->set_leader(me);
  message_vision(msg,mob,me);
  while(j-- > 0) {
    COMBAT_D->do_attack(mob,enemy[i],mob->query_temp("weapon"),2);
  }

  if (msg2) { message_vision(msg2,mob,me); } //有個人特色訊息時
  else { message_vision(BLINK+HIY + "哎呀！醬油忘記拿了…\n" + NOR,me,target); }

  destruct(present(mob->query("id"),environment(me)));

//me->set_temp("bewitching",1);
//call_out( 字串 或 函式 fun, 整數 delay, 混合 arg );
//call_out("act1",1,msg,target,me,fun,k);
return 1;

}

//效果消失時 不做訊息(msg)的表達? 不讓玩家容易抓到觸發?
int act1(string msg,object target,object me,int fun,int k)
{
  if(!me) return 1;
  me->set_temp("bewitching",0);
  if(!target || !me) return 1;
  if(!target) return 1;
/*  if(me->is_fighting(target)) {
    if(80>random(100))
    {
      msg = HIM + "結果$p被$P的火球術擊中！\n" + NOR;
      target->receive_wound("kee",k+200,me);
      target->apply_condition("burn",random(10) +fun/10);
    } 
    else
    {
      msg = CYN + "結果$p躲過了$P的火球術。\n" + NOR;
    }
      me->add("atman",-50);
      message_vision(msg, me, target);
      COMBAT_D->report_status(target);
//      if(fun<100) spell_improved("bewitching",random(50));
  }*/
  return 1;
}
