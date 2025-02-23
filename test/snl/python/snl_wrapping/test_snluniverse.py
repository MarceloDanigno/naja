# SPDX-FileCopyrightText: 2023 The Naja authors <https://github.com/xtofalex/naja/blob/main/AUTHORS>
#
# SPDX-License-Identifier: Apache-2.0

import unittest
import snl

class SNLUniverseTest(unittest.TestCase):
  def tearDown(self):
    if snl.SNLUniverse.get():
      snl.SNLUniverse.get().destroy()

  def test(self):
    self.assertIsNone(snl.SNLUniverse.get())
    snl.SNLUniverse.create()
    self.assertIsNotNone(snl.SNLUniverse.get())
    self.assertIsNone(snl.SNLUniverse.get().getTopDesign())

if __name__ == '__main__':
  unittest.main()
