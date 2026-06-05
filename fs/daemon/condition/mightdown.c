//在非戰鬥中就會刪除狀態的模式 所以在condition裡設定
//分為兩段 戰鬥狀態 與 獲得經驗兩階段 判斷刪除狀態的時機

#include <ansi.h>
inherit F_FUNCTION;
int update_condition(object me, int duration)
{
	if(duration > 0)
	{
		int att1,saulinforce;
		int fun = me->query("functions/mightup/level"),g;
		if(!fun) {fun=1;} //當尚未學習技能時 需設為基礎值 1 否則下列判斷時 不會獲得經驗
		saulinforce=me->query_skill("saulinforce",1);
		g=me->query_temp("might-bonze"); //因為重登 所以此數值不存在 >> g=0 所以 以下皆沒有影響
//a && b
		if(!me->is_fighting() && me && me->query_temp("mightup")) { //如果在非戰鬥時 且 驅使阿羅漢之力時
			message_vision(HIB + "$N身上賁起的肌肉猶如洩了氣般恢復平常。\n" + NOR,me);
			me->delete_temp("mightup",1); //刪除參數則狀態會消失 但是condition還在做判斷 但是可能會被累計 所以需做額外固定變數的設定做判斷
			me->add_temp("apply/damage",-g);
			if(me->query("bonze/mightup_get_exp",1)) {me->apply_condition("mightdown",0);} //已經因為過久的戰鬥中獲得經驗 且 戰鬥完畢 則停止狀態
			}
//!b <<<含 !a && !b 與 a && !b
		else if(!me->query_temp("mightup")) {} //避免離線 或 非戰鬥 會有訊息 //因為要持續判斷 所以保留 故不使用return 使跳出if 使持續做經驗的判斷
//!a && b 與 !a && !b >>> 所以剩下 !a && b >> 當me->is_fighting() && me->query_temp("mightup")
		else {//其他就是當me->is_fighting() && me->query_temp("mightup")的情況
			tell_object(me,HIM + "你舉手投足間賁起身上線條分明的肌肉，大展身為熱血沸騰『" + HIG + "血脈賁張" + HIM + "』的硬漢本色。\n" + NOR); //由於少林只有男性所以不考慮女性形容
			message("vision",HIM+me->name()+"身上的肌肉真的是青筋滿佈，表現出男人『" + HIG + "血脈賁張" + HIM + "』力與美的硬漢本色。\n" + NOR,environment(me),me);
			}
//為 !c(經驗參考值不存在 or 等於零 也符合條件！) 且 fun 未滿100 且此次perform沒獲得經驗
//		if(!me->query("bonze/mightup_exp",1) && me->query("bonze/mightup_exp",1) != 0 && fun < 100 && !me->query("bonze/mightup_get_exp",1)) {
		if(!me->query("bonze/mightup_exp") && fun < 100 && !me->query("bonze/mightup_get_exp",1)) {
//			if(!me->query("bonze/mightup_get_exp") ) {//似乎不能與上列合併判斷 因為會造成無限迴圈
				me->set("bonze/mightup_exp",fun+1); //因為本數值不存在也等同於零 所以額外加1 為了使下方判斷改為不以零做判斷
				if(wizardp(me)) {
					write(HBYEL + "【巫師專用測試資料】設置經驗增加ok！\n" + NOR,me); //測試
					}
				return 1; //做跳出 不使下列做判斷 //使下一次的condition做判斷
//				}
			}
//當fun不到lv100 且不超過內功心法時 且 經驗增加參考值存在時
//(此值的存在與否 即重登與否 <<<應該是 原先的取得經驗時 卻在恢復正常時才有的判斷 卻因為重登 所以 不存在所引起的)
//所以 獨立做經驗的判斷
		if(fun < 100 && fun < saulinforce && me->query("bonze/mightup_exp") ) {
//只有在經驗增加參考值為1時 才有經驗 其他情況 一概不增加 //為零時 等同於該數值不存在 在上述的判斷時 就會改為增加經驗的判斷
			if(me->query("bonze/mightup_exp",1)==1) {
				function_improved("mightup",(fun+random(saulinforce*2)));
				if(wizardp(me)) {
					write(HBMAG + "【巫師專用測試資料】你的阿羅漢之力略有進展。\n" + NOR,me); //測試
					}
				me->delete("bonze/mightup_exp"); //刪除經驗增加參考值
				if(!me->is_fighting()) { //非戰鬥中 就解除本condition了
					me->apply_condition("mightdown",0);
//					return 0; //理論上 應為解除狀態 //留到最後做參數的刪除
					}
				else {me->set("bonze/mightup_get_exp",1);} //若在戰鬥中 就設定額外參數 不解除本condition了
				}
			else if(me->query("bonze/mightup_exp",1) >0) {
				me->add("bonze/mightup_exp",-1); //為遞減式
				if(wizardp(me)) {
					write(HBGRN + "【巫師專用測試資料】condition運轉中\n" + NOR,me); //測試
					}
				return 1; //理論上 應為持續狀態
				}
			else {
				me->delete("bonze/mightup_exp");
				if(wizardp(me)) {
					write(HBRED + "【巫師專用測試資料】刪除經驗的狀況一\n" + NOR,me); //測試
					}
				} //刪除經驗增加參考值 避免有負數的情況
			}
	return 1;
	} //if(duration > 0)
me->delete_temp("might-bonze");
me->delete("bonze/mightup_get_exp");
return 0; 
}