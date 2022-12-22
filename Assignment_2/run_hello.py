import m5
from m5.objects import *

root = Root(full_system = False)

# vector_latency = input()
# add_latency = input()
# dot_latency = input()
# normalize_latency = input()
a = input()
b = input()
c = input()
d = input()

# e = input()
# f = input()
# g = input()
# h = input()
# i = input()
# j = input()
# k = input()
# l = input()

root.hello = VectorOperations(time_to_wait1 = a,time_to_wait2=b,time_to_wait3=c,time_to_wait4=d)

m5.instantiate()

print("Beginning simulation!")
exit_event = m5.simulate()
print('Exiting @ tick {} because {}'
      .format(m5.curTick(), exit_event.getCause()))