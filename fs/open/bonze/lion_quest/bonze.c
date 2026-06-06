//參考/open/fire-hole/firestorm.c 的經驗值判斷
//繼承上列firestorm.c傷害的判斷
//本段函數作為經驗值限定下限的參考方式 by blazakira
//繼承傷害的判斷 並設定與殺氣連動 參考少林正面的形象而設計 by blazakira

#include <ansi.h>

void init()
{
  if( random(this_player()->query("bellicosity")) > 1500 && !this_player()->query_temp("quests/bonze/mob") ) //將本區mob特有的set_temp 作為判斷之一
  {
    this_player()->set_temp("bonze_sanskrit",1); //設定此和尚_梵文為 判斷變數
    tell_object(this_player(),HIW"\n風中傳來少林寺裡隱隱誦經的梵音，使你大有放下屠刀立地成佛之感。\n"NOR);
  }
  call_out("do_check",1,this_player()); //呼叫函數
  add_action("do_back","back"); //作為在此區域 方便回到入口的動作函數
}

int do_back(string str)
{
  object me=this_player();
  if( !me->query_temp("leave_bonze") ) //如果set_temp的mark ("leave_bonze") 不存在 那就繼續下列判斷
  {
    tell_object( me , HIG"客官請問您要離開這裡了嗎？請再下一次 "HIC"(back)"HIG" 確認。\n"NOR);
    me->set_temp("leave_bonze",1);
    return 1;
  }
  tell_object( me , HIG"小的馬上來為您服務。\n\n"NOR);
  me->delete_temp("leave_bonze"); //刪除set_temp 也需使用delete_temp以示區別
  me->move("/open/bonze/room/r2");
  me->reset_action();
  return 1;
}

void do_check(object me)
{
  int damage; //設定變數
//可參考bonze/room/q01.c 或是原檔案/open/fire-hole/firestorm.c
  if(!me) return;
  if(me->query_temp("bonze_sanskrit")) //判斷基準
  {
    damage = 170; //暫定傷害為170
    tell_object (me,BMAG+HIY"因你無法控制你自己高昂的殺氣而受了點輕微內傷。\n"NOR);
    me->receive_damage("kee",damage); //以上判斷完畢後 給予該人物傷害
    me->add("bellicosity", -3); //減少殺氣10 作為通路費 //暫定為3 比較不會那麼傷
    COMBAT_D->report_status(me); //回報傷害訊息給該人物
    me->delete_temp("bonze_sanskrit"); //刪除判斷變數 以便下次重新判斷所給予的傷害與否
  }
//玩家經驗值多寡的判斷
  if(me->query("combat_exp" ) < 4500000 && userp(me) && living(me))
  {
    message_vision(HIC"抱歉，前方的路對$P來說太艱辛了，大俠$N請回吧！\n\n"NOR,me);
    me->move("/open/bonze/room/r2");
  } else  
    me->set_temp("check_ok",1); //如果判斷通過就作檢查ok的標記
}
