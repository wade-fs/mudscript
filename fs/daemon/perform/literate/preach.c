// preach.c by Onion
// 重新QC及修正by chan
// By Swy 最後修正 QC 98/6/21
inherit SSERVER;
int perform(object me, object target)
{
	string *ATTACK_MSG=({
	"$N發揮書生的本色開始對$n訓示「曾氏家訓」的意義。",
	"$N開始滔滔不絕對$n講解「三字經」的大意。",
	"$N翻開隨身攜帶的「論語」, 對$n講述孔子的志向。",
	"$N苦口婆心的勸導$n要立志向善, 做大事, 成大業。",
	"$N從背後掏出鞭子對$n恐嚇說: 不聽話要處以「暫時性疼痛」的處法喔。",
	"$N開始對$n朗誦「百家姓」、「千字文」各一遍。"
	});
	int action=random(sizeof(ATTACK_MSG));
	if( target == me )
	  return notify_fail("不能對付自己呀!!\n");
	if( !target )
	if( !target = offensive_target(me) )
		return notify_fail("沒有這個對象。\n");
	if( target->query_temp("preach") )
	  return notify_fail("這招沒用了。\n");
if( me->query("water") < 20)
	  return notify_fail("你的'口水'準備不夠喔。\n");
	if( me->query("force") <= 0 )
	  return notify_fail("你的內力不夠。\n");
	if( !me->query_skill("literate") )
          return notify_fail("先學點基本的學識。\n");
        if( !me->is_fighting() )
	  return notify_fail("戰鬥中訓示對方比較有效喔。\n");
        message_vision("\n[36m"+ATTACK_MSG[action]+"[0m\n\n",me,target);
	target->set_temp("preach",1);
     if(target->is_busy())
       return notify_fail("敵人不能動快攻擊哦!!!\n");
	target->start_call_out( (: call_other, __FILE__, "do_result",me,target :),3);
	return 1;
}
void do_result(object me,object target)
{
	if( target->query("race") != "人類" )
	  message_vision("$N瞪著一雙大眼睛好奇的望著$n。\n",target,me);
	else
	  if( random(3) > 0 )
          {
	    message_vision("[1;36m$N雙手抱著頭大叫: 阿~~....顯然受不了$n的魔音。\n[0m",target,me);
     target->start_busy(2);
	  }
	  else
	    message_vision("$N絲毫不受影響..\n",target);
    me->start_busy(1);
}
