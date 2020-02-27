#!/bin/bash
export OMP_NUM_THREADS=4
srun ./wcd -m input.in -t 4
