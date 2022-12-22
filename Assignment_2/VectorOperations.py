from m5.params import *
from m5.SimObject import SimObject

class VectorOperations(SimObject):
    type = 'VectorOperations'
    cxx_header = "learning_gem5/CA_Assign2/vector_operations.hh"
    # tick_1 = Param.Latency()
    # tick_2 = Param.Latency()
    # tick_3 = Param.Latency()
    # tick_4 = Param.Latency()
    time_to_wait1 = Param.Int("")
    time_to_wait2 = Param.Int("")
    time_to_wait3 = Param.Int("")
    time_to_wait4 = Param.Int("")

    # vec1_0 = Param.Int("")
    # vec1_1 = Param.Int("")
    # vec1_2 = Param.Int("")
    # vec1_3 = Param.Int("")
    # vec2_4 = Param.Int("")
    # vec2_5 = Param.Int("")
    # vec2_6 = Param.Int("")
    # vec2_7 = Param.Int("")
    cxx_class = "gem5::VectorOperations"

