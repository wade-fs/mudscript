// mudlib/cmds/cmd_movement.c
// 移動指令守護進程：north / south / east / west / up / down / go

int main(object me, string verb, string arg) {
    object here = environment(me);
    if (!here) {
        write("你不在任何地方。\n");
        return 1;
    }

    string dir = arg;

    if (verb == "go") {
        if (!arg || arg == "") {
            write("要往哪裡去？例如：go north\n");
            return 1;
        }
        dir = arg;
    } else {
        dir = verb;
    }

    return here->do_go(dir);
}

string help() {
    return "【移動指令】\n" +
           "  north / south / east / west  往四個方向移動\n" +
           "  up / down                    往上 / 往下移動\n" +
           "  go <方向>                    明確移動，例如：go north\n";
}
