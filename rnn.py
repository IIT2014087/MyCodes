import numpy as np
import code
from imagernn.utils import merge_init_structs, initw, accumNpDicts
from imagernn.lstm_generator import LSTMGenerator
from imagernn.rnn_generator import RNNGenerator

def decodeGenerator(generator):
  if generator == 'lstm':
    return LSTMGenerator
  if generator == 'rnn':
    return RNNGenerator
  else:
    raise Exception('generator %s is not yet supported' % (base_generator_str,))
