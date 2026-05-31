//起死回生之術 by bss
//加入quest的判斷 by blazakira 2011/3/22

#include <ansi.h>
inherit F_CLEAN_UP;
void move_obj(object corpse,object ppl);
void good_work(object me,object ppl,object corpse);
void bad_work(object ppl,object corpse,int stat);
void act(object me,object ppl,object corpse);

int main(object me, string arg)
{
    object ppl,corpse;
    string id,name;

    seteuid(getuid());
    if(me->query("class") != "doctor" && !wizardp(me))
      return 0;
    if(!wizardp(me)) return 0;
    if(!me->query("doctor/save_die"))
      return 0;
    if(me->query("doctor/save_die_time") > time() && !wizardp(me))
      return notify_fail("在一天之中沒有辦法連救兩個人!!\n");
    if(!arg) return notify_fail("你想要救活誰???\n");
    if(!corpse=present(arg,environment(me)))
      return notify_fail("沒有你想要救的那個東西!!\n");
    if(me->query("force") < 2000)
      return notify_fail("你的內力不夠!!!\n");
    if(me->is_fighting())
      return notify_fail("戰鬥中不能幫人復活!\n");
    id=corpse->query("victim_id");
    if(wizardp(me)) printf("id=%s\n",id);
    name=corpse->query("victim_name");
    if(!name && !id) {
      id=corpse->query("id");
      name=corpse->query("name");
    }
    if(!ppl=find_player(id)) //可能離線了，可能不是玩家
      return notify_fail(sprintf("%s(%s) 這個人已經用不著你救了!!!\n",name,id));
    if(ppl->query_temp("net_dead"))
      return notify_fail(sprintf("%s(%s) 這個人已經沒有救了!!!\n",name,id));
    if(in_edit(ppl) || in_input(ppl))
        return notify_fail(sprintf("%s(%s) 這個人在救治的過程中受到阻礙!!!\n",name,id));
    if(corpse->query("no_save_die")) //屍體已經腐化了
      return notify_fail(sprintf("你沒辦法讓屍體都腐化的人起死回生!!!\n",name,id));
    if(!ppl->query("ghost")) //已經出鬼門關了
      return notify_fail(sprintf("%s(%s) 這個人不用你救，已經出鬼門關了!!!\n",name,id));
    me->set("doctor/save_die_time",time()+86400);
    message_vision("
$N施展出銀針門秘傳絕技「聖手回春術」，將手搭在$n的頭頂與氣海，灌輸自己的
真氣，想要把$n從鬼門關救回來!!!\n",me,ppl);
    tell_object(ppl,"
你感到你的身體竟然開始散發著光芒，你覺得你好像快要復活了!!!\n");
    me->set_temp("save_die/limit",ppl->query("max_force")*8);
    me->set_temp("saving_die",1);
    me->set_temp("不准走",1);
    call_out("act",3,me,ppl,corpse);

    return 1;
}

void act(object me,object ppl,object corpse)
{
    int force_value;

    if(!me){//施救者離線，不存在，stat=1
      bad_work(ppl,corpse,1);
      return ;
    }
    if(!ppl){//被救者離線，不存在，stat=2
      bad_work(me,corpse,2);
      return ;
    }
    if(!corpse){//屍體不見了，stat=3
      bad_work(me,ppl,3);
      return;
    }
    if(!present(geteuid(me),environment(corpse))){//施救者離開了屍體，stat=4
      bad_work(me,ppl,4);
      return ;
    }
    if(!ppl->query("ghost")){ //已經出鬼門關了，stat=5
      bad_work(me,ppl,5);
      return ;
    }
    force_value=me->query("env/use_force");
    if(!force_value) force_value=1000;
    if(force_value < 1000) force_value=1000;
    me->add("force",-force_value);
    if(me->query("force")<1){//施救者的內力不夠，stat=6
      bad_work(me,ppl,6);
      return ;
    }
    message_vision("$N將自身的內力不停的灌到$n的體內，試著接回$n體內已經斷了的經脈!!\n",me,ppl);
    me->add_temp("save_die/point",force_value);
    if(me->query_temp("save_die/point") >= me->query_temp("save_die/limit")){
      good_work(me,ppl,corpse);
      return ;
    }
    call_out("act",3,me,ppl,corpse);
    return;
}
void bad_work(object ppl,object corpse,int stat)
{

    switch(stat){
      case 1:
        if(ppl){
          tell_object(ppl,"你身上的光芒漸漸的消失，看來你的復活失敗了!!\n");
        }
        break;
      case 2:
        if(ppl){
          tell_object(ppl,"你想要救的人忽然吐出一大口鮮血，看來是救不活了!!!\n");
          ppl->delete_temp("save_die");
          ppl->delete_temp("saving_die");
          ppl->delete_temp("不准走");
        }
        break;
      case 3:
        tell_object(ppl,"你發現你想要救的人不見了???看來屍體被偷走了!!\n");
        tell_object(corpse,"你身上的光芒漸漸的消失，看來你的復活失敗了!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        break;
      case 4:
        tell_object(ppl,"你離開了你要救的人，看來他是不能活的了!!\n");
        tell_object(corpse,"你身上的光芒漸漸的消失，看來你的復活失敗了!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        break;
      case 5:
        tell_object(ppl,"你想要救的人忽然吐出一大口鮮血，看來是救不活了!!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        break;
      case 6:
        message_vision("
$N因為顧著救人，耗光了身上所有的內力!!!
$N看起來搖搖欲墜，已經支持不下去了!!!\n",ppl);
        tell_object(corpse,"你身上的光芒漸漸的消失，看來你的復活失敗了!!\n");
        ppl->delete_temp("save_die");
        ppl->delete_temp("saving_die");
        ppl->delete_temp("不准走");
        ppl->unconcious();
        break;
    }
    return ;
}

void good_work(object me,object ppl,object corpse)
{
    int exp = (int)ppl->query("combat_exp")/25;
    if(exp > 50000) exp = 50000;

    tell_object(ppl,"
你突然覺得一股強大的吸力出現在你身後，強大的吸力使你不由自主的向後飄飛!!!\n");
    ppl->remove_call_out("revive");
    ppl->relive();
    ppl->move(environment(me));
    ppl->reincarnate();
    move_obj(corpse,ppl);
    destruct(corpse);
    me->delete_temp("save_die");
    me->delete_temp("saving_die");
    me->delete_temp("不准走");
    me->add("combat_exp",exp);
    message_vision("$N終於把$n給救活了，不過也累出了滿身大汗!!\n",me,ppl);
    log_file("SAVE_DIE",sprintf("(%s)把%s(%s)給救活了在 %s\n",
    me->query("id"),ppl->query("name"),ppl->query("id"),ctime(time())));
    message_vision("$N因此獲得了"+exp+"點的經驗值！\n",me);
    return ;
}

void move_obj(object corpse,object ppl)
{
    object *inv;
    int i;

    if(!corpse || !ppl) return ;
    inv=all_inventory(corpse);
    for(i=0;i<sizeof(inv);i++)
      inv[i]->move(ppl);

    return ;
}
