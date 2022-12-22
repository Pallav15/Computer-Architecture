
import m5
from m5.objects import *

from caches import *

system = System()

system.clk_domain = SrcClockDomain()
system.clk_domain.clock = '1GHz'
system.clk_domain.voltage_domain = VoltageDomain()

system.mem_mode = 'timing'               
system.mem_ranges = [AddrRange('512MB')] 
system.cpu = TimingSimpleCPU()

system.cpu.icache = L1ICache()
system.cpu.dcache = L1DCache()

system.cpu.icache.connectCPU(system.cpu)
system.cpu.dcache.connectCPU(system.cpu)

system.l2bus = L2XBar()

system.cpu.icache.connectBus(system.l2bus)
system.cpu.dcache.connectBus(system.l2bus)

system.l2cache = L2Cache()
system.l2cache.connectCPUSideBus(system.l2bus)

system.membus = SystemXBar()

system.l2cache.connectMemSideBus(system.membus)

system.cpu.createInterruptController()

system.cpu.interrupts[0].pio = system.membus.mem_side_ports
system.cpu.interrupts[0].int_requestor = system.membus.cpu_side_ports
system.cpu.interrupts[0].int_responder = system.membus.mem_side_ports

system.mem_ctrl = MemCtrl()
system.mem_ctrl.dram = DDR3_1600_8x8()
system.mem_ctrl.dram.range = system.mem_ranges[0]
system.mem_ctrl.port = system.membus.mem_side_ports


system.system_port = system.membus.cpu_side_ports 

isa = "x86"

binary = "/home/cse511m2022/pallav20225/gem5/configs/CATutorial/qsort/qsort_small"
system.workload = SEWorkload.init_compatible(binary)

process = Process()
process.cmd = [binary,"/home/cse511m2022/pallav20225/gem5/configs/CATutorial/qsort/input_small.dat"]
system.cpu.workload = process
system.cpu.createThreads()

root = Root(full_system = False, system = system)

m5.instantiate()

print("Beginning simulation!")
exit_event = m5.simulate()
print('Exiting @ tick %i because %s' % (m5.curTick(), exit_event.getCause()))
