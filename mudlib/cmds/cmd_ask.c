// mudlib/cmds/cmd_ask.c
// 詢問指令：ask <目標> about <話題>

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg) {
        write("詢問誰？用法：ask <目標> about <話題>\n");
        return 1;
    }

    string target_id, topic;

    // 優先嘗試 "X about Y" 格式
    // LPC sscanf 的 %s 是 non-greedy，遇到字面量 " about " 就停止第一個 %s
    if (sscanf(arg, "%s about %s", target_id, topic) == 2 &&
        target_id != "" && topic != "") {
        // 解析成功
    } else if (sscanf(arg, "%s %s", target_id, topic) == 2 &&
               target_id != "" && topic != "") {
        // 簡寫格式：ask <目標> <話題>
    } else {
        write("詢問關於什麼？用法：ask <目標> about <話題>\n");
        return 1;
    }

    // 在目前房間尋找目標，present() 使用 id() 比對 id_list
    object target = present(target_id, environment(me));
    if (!target) {
        write("這裡沒有「" + target_id + "」這個人。\n");
        return 1;
    }

    if (!living(target)) {
	    write("你要問一尊雕像什麼嗎？\n");
	}

    string target_name = target->query_name();

    // 用 tell_object 確保訊息送給正確的玩家
    tell_object(me, "你向 " + target_name + " 詢問關於「" + topic + "」的事。\n");
	tell_room(environment(me),
    	me->query_name() + " 向 " + target_name + " 詢問了一些事。\n", ({ me }));

    // 呼叫 NPC 的 do_chat，傳入詢問者 me 方便 NPC 直接 tell_object
    if (!target->do_chat(me, topic)) {
        tell_object(me, target_name + " 只是看了看你，什麼也沒說。\n");
    }

    return 1;
}

string help() {
    return "【詢問指令】\n" +
           "  ask <目標> about <話題>    向 NPC 詢問特定的資訊\n" +
           "  ask <目標> <話題>          詢問的簡寫方式\n" +
           "\n" +
           "  範例：ask master about job\n" +
           "  範例：ask 會長 about 公會\n" +
           "  範例：ask master topics     （查看可詢問的話題）\n";
}
