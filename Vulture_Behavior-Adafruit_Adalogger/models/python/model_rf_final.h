#pragma once
#define PROB

const char* idxToLabel(uint8_t);

/**
* get probalility for prediction from votes
*/
float get_prob(uint8_t *votes, uint8_t idx){
	uint8_t sum = 0;
	for(uint8_t i = 0; i < 3; i++){
		sum += votes[i];
	}
	return (float)votes[idx]/(float)sum;
}

/**
* Predict class for features vector
*/
int predict(float *x, float *prob) {
	uint8_t votes[3] = { 0 };
	// tree #1
	if (x[3] <= 0.369140625) {
		if (x[0] <= 0.017429144121706486) {
			if (x[1] <= 0.7164684534072876) {
				if (x[0] <= 0.0035269882064312696) {
					votes[1] += 1;
				}

				else {
					if (x[1] <= -0.591683566570282) {
						votes[1] += 1;
					}

					else {
						if (x[0] <= 0.003600541385821998) {
							if (x[3] <= 0.029296875) {
								if (x[0] <= 0.0035450865980237722) {
									votes[0] += 1;
								}

								else {
									votes[1] += 1;
								}
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							if (x[1] <= 0.45719943940639496) {
								if (x[3] <= 0.0400390625) {
									votes[1] += 1;
								}

								else {
									if (x[2] <= 0.007126210257411003) {
										votes[0] += 1;
									}

									else {
										if (x[2] <= 0.01811310462653637) {
											votes[1] += 1;
										}

										else {
											if (x[2] <= 0.018735221587121487) {
												votes[0] += 1;
											}

											else {
												votes[1] += 1;
											}
										}
									}
								}
							}

							else {
								if (x[3] <= 0.0595703125) {
									votes[1] += 1;
								}

								else {
									if (x[1] <= 0.5889189541339874) {
										votes[0] += 1;
									}

									else {
										votes[1] += 1;
									}
								}
							}
						}
					}
				}
			}

			else {
				if (x[3] <= 0.056640625) {
					votes[1] += 1;
				}

				else {
					votes[0] += 1;
				}
			}
		}

		else {
			if (x[3] <= 0.09765625) {
				if (x[2] <= 0.016911128535866737) {
					if (x[2] <= 0.01523651136085391) {
						votes[1] += 1;
					}

					else {
						if (x[1] <= 0.15663468837738037) {
							votes[1] += 1;
						}

						else {
							votes[0] += 1;
						}
					}
				}

				else {
					if (x[1] <= 0.22756321728229523) {
						votes[1] += 1;
					}

					else {
						votes[0] += 1;
					}
				}
			}

			else {
				if (x[1] <= 0.21810884773731232) {
					if (x[3] <= 0.23828125) {
						votes[1] += 1;
					}

					else {
						if (x[3] <= 0.2587890625) {
							votes[2] += 1;
						}

						else {
							if (x[0] <= 0.06684018298983574) {
								if (x[1] <= -0.4515354633331299) {
									votes[1] += 1;
								}

								else {
									votes[0] += 1;
								}
							}

							else {
								votes[2] += 1;
							}
						}
					}
				}

				else {
					if (x[1] <= 0.4899807870388031) {
						if (x[3] <= 0.2685546875) {
							if (x[3] <= 0.1494140625) {
								if (x[1] <= 0.48064103722572327) {
									votes[0] += 1;
								}

								else {
									votes[1] += 1;
								}
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							if (x[0] <= 0.0823984369635582) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						if (x[0] <= 0.11462144553661346) {
							if (x[2] <= 0.05726778879761696) {
								votes[0] += 1;
							}

							else {
								if (x[1] <= 0.808025449514389) {
									if (x[2] <= 0.057805607095360756) {
										votes[2] += 1;
									}

									else {
										votes[0] += 1;
									}
								}

								else {
									votes[0] += 1;
								}
							}
						}

						else {
							if (x[0] <= 0.1185377761721611) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}
					}
				}
			}
		}
	}

	else {
		if (x[3] <= 0.4951171875) {
			if (x[0] <= 0.0631372295320034) {
				if (x[3] <= 0.4873046875) {
					if (x[1] <= 0.7692849934101105) {
						votes[2] += 1;
					}

					else {
						votes[0] += 1;
					}
				}

				else {
					votes[0] += 1;
				}
			}

			else {
				if (x[1] <= 0.43847569823265076) {
					votes[2] += 1;
				}

				else {
					if (x[0] <= 0.1282353475689888) {
						if (x[3] <= 0.373046875) {
							votes[2] += 1;
						}

						else {
							if (x[2] <= 0.09593993425369263) {
								votes[0] += 1;
							}

							else {
								if (x[1] <= 0.6295208930969238) {
									votes[2] += 1;
								}

								else {
									if (x[2] <= 0.1028858944773674) {
										if (x[2] <= 0.09879008308053017) {
											votes[0] += 1;
										}

										else {
											votes[2] += 1;
										}
									}

									else {
										votes[0] += 1;
									}
								}
							}
						}
					}

					else {
						votes[2] += 1;
					}
				}
			}
		}

		else {
			if (x[1] <= 0.8041864335536957) {
				if (x[0] <= 1.0791631937026978) {
					if (x[1] <= 0.41837137937545776) {
						if (x[0] <= 0.6329401135444641) {
							if (x[2] <= 0.10282380133867264) {
								if (x[2] <= 0.10163585469126701) {
									votes[2] += 1;
								}

								else {
									votes[1] += 1;
								}
							}

							else {
								if (x[2] <= 0.2849096357822418) {
									if (x[2] <= 0.15268460661172867) {
										if (x[2] <= 0.15109405666589737) {
											votes[2] += 1;
										}

										else {
											votes[0] += 1;
										}
									}

									else {
										votes[2] += 1;
									}
								}

								else {
									if (x[2] <= 0.285039022564888) {
										votes[0] += 1;
									}

									else {
										votes[2] += 1;
									}
								}
							}
						}

						else {
							if (x[2] <= 0.20045693963766098) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						if (x[2] <= 0.1893731951713562) {
							if (x[3] <= 0.8271484375) {
								if (x[0] <= 0.06047838740050793) {
									if (x[2] <= 0.09298010170459747) {
										votes[0] += 1;
									}

									else {
										votes[2] += 1;
									}
								}

								else {
									if (x[2] <= 0.13578251004219055) {
										if (x[0] <= 0.08598697744309902) {
											votes[2] += 1;
										}

										else {
											votes[0] += 1;
										}
									}

									else {
										votes[2] += 1;
									}
								}
							}

							else {
								if (x[0] <= 0.09238230437040329) {
									votes[2] += 1;
								}

								else {
									if (x[1] <= 0.527337521314621) {
										votes[0] += 1;
									}

									else {
										if (x[2] <= 0.1702871024608612) {
											votes[2] += 1;
										}

										else {
											votes[0] += 1;
										}
									}
								}
							}
						}

						else {
							votes[2] += 1;
						}
					}
				}

				else {
					if (x[3] <= 2.5322265625) {
						if (x[1] <= 0.07879592850804329) {
							votes[0] += 1;
						}

						else {
							if (x[0] <= 1.0912840366363525) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						votes[2] += 1;
					}
				}
			}

			else {
				if (x[1] <= 0.8313004970550537) {
					if (x[2] <= 0.16438736766576767) {
						votes[2] += 1;
					}

					else {
						votes[0] += 1;
					}
				}

				else {
					votes[0] += 1;
				}
			}
		}
	}

	// tree #2
	if (x[3] <= 0.37109375) {
		if (x[1] <= 0.4948432892560959) {
			if (x[0] <= 0.035456396639347076) {
				if (x[1] <= 0.4488320052623749) {
					if (x[0] <= 0.006135657196864486) {
						if (x[3] <= 0.0166015625) {
							if (x[2] <= 0.0040912514086812735) {
								votes[1] += 1;
							}

							else {
								if (x[1] <= -0.39536938071250916) {
									votes[1] += 1;
								}

								else {
									if (x[1] <= -0.30565278232097626) {
										votes[0] += 1;
									}

									else {
										votes[1] += 1;
									}
								}
							}
						}

						else {
							votes[1] += 1;
						}
					}

					else {
						if (x[1] <= -0.33306728303432465) {
							if (x[1] <= -0.8622606694698334) {
								if (x[3] <= 0.0732421875) {
									votes[1] += 1;
								}

								else {
									if (x[3] <= 0.0908203125) {
										votes[0] += 1;
									}

									else {
										votes[1] += 1;
									}
								}
							}

							else {
								votes[1] += 1;
							}
						}

						else {
							if (x[1] <= -0.3135160356760025) {
								votes[0] += 1;
							}

							else {
								if (x[2] <= 0.007530311355367303) {
									if (x[2] <= 0.006442417157813907) {
										votes[1] += 1;
									}

									else {
										votes[0] += 1;
									}
								}

								else {
									if (x[3] <= 0.0576171875) {
										if (x[0] <= 0.006339302286505699) {
											votes[0] += 1;
										}

										else {
											if (x[3] <= 0.0546875) {
												votes[1] += 1;
											}

											else {
												if (x[0] <= 0.010987269226461649) {
													votes[1] += 1;
												}

												else {
													votes[0] += 1;
												}
											}
										}
									}

									else {
										votes[1] += 1;
									}
								}
							}
						}
					}
				}

				else {
					if (x[0] <= 0.008844256517477334) {
						votes[1] += 1;
					}

					else {
						if (x[1] <= 0.4780493229627609) {
							votes[0] += 1;
						}

						else {
							votes[1] += 1;
						}
					}
				}
			}

			else {
				if (x[0] <= 0.07210175693035126) {
					if (x[1] <= -0.5999242067337036) {
						if (x[1] <= -0.7310614585876465) {
							votes[1] += 1;
						}

						else {
							votes[2] += 1;
						}
					}

					else {
						votes[0] += 1;
					}
				}

				else {
					if (x[0] <= 0.0823984369635582) {
						if (x[0] <= 0.07663681730628014) {
							votes[2] += 1;
						}

						else {
							votes[0] += 1;
						}
					}

					else {
						votes[2] += 1;
					}
				}
			}
		}

		else {
			if (x[3] <= 0.0615234375) {
				votes[1] += 1;
			}

			else {
				if (x[2] <= 0.05737367086112499) {
					votes[0] += 1;
				}

				else {
					if (x[1] <= 0.8058126270771027) {
						if (x[2] <= 0.057805607095360756) {
							votes[2] += 1;
						}

						else {
							votes[0] += 1;
						}
					}

					else {
						votes[0] += 1;
					}
				}
			}
		}
	}

	else {
		if (x[1] <= 0.8020239174365997) {
			if (x[2] <= 0.12569691240787506) {
				if (x[3] <= 0.638671875) {
					if (x[2] <= 0.08124644681811333) {
						if (x[0] <= 0.10578100010752678) {
							if (x[1] <= -0.06089946627616882) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							votes[2] += 1;
						}
					}

					else {
						if (x[0] <= 0.09166709706187248) {
							if (x[1] <= 0.17670371383428574) {
								votes[2] += 1;
							}

							else {
								if (x[0] <= 0.06541391462087631) {
									votes[2] += 1;
								}

								else {
									if (x[0] <= 0.07160596549510956) {
										votes[0] += 1;
									}

									else {
										if (x[0] <= 0.07506655529141426) {
											votes[2] += 1;
										}

										else {
											if (x[3] <= 0.50390625) {
												votes[0] += 1;
											}

											else {
												votes[2] += 1;
											}
										}
									}
								}
							}
						}

						else {
							votes[2] += 1;
						}
					}
				}

				else {
					if (x[3] <= 0.701171875) {
						if (x[1] <= 0.16973259299993515) {
							votes[0] += 1;
						}

						else {
							if (x[0] <= 0.10333878919482231) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						votes[2] += 1;
					}
				}
			}

			else {
				if (x[1] <= 0.15170946717262268) {
					if (x[2] <= 0.32739001512527466) {
						if (x[0] <= 0.7738656103610992) {
							votes[2] += 1;
						}

						else {
							if (x[2] <= 0.18436646461486816) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						if (x[0] <= 1.0725373029708862) {
							votes[2] += 1;
						}

						else {
							if (x[2] <= 0.44208015501499176) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}
				}

				else {
					if (x[0] <= 0.9614005982875824) {
						if (x[1] <= 0.15324071794748306) {
							votes[0] += 1;
						}

						else {
							if (x[3] <= 1.13671875) {
								if (x[2] <= 0.2721497118473053) {
									if (x[0] <= 0.3370473235845566) {
										if (x[3] <= 1.1279296875) {
											votes[2] += 1;
										}

										else {
											votes[0] += 1;
										}
									}

									else {
										if (x[2] <= 0.1638609543442726) {
											if (x[1] <= 0.5328604727983475) {
												votes[0] += 1;
											}

											else {
												votes[2] += 1;
											}
										}

										else {
											votes[2] += 1;
										}
									}
								}

								else {
									votes[0] += 1;
								}
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						if (x[2] <= 0.47764865309000015) {
							votes[0] += 1;
						}

						else {
							votes[2] += 1;
						}
					}
				}
			}
		}

		else {
			if (x[0] <= 0.083330187946558) {
				if (x[0] <= 0.07352831214666367) {
					votes[0] += 1;
				}

				else {
					if (x[3] <= 0.41015625) {
						votes[0] += 1;
					}

					else {
						votes[2] += 1;
					}
				}
			}

			else {
				votes[0] += 1;
			}
		}
	}

	// tree #3
	if (x[0] <= 0.017739676870405674) {
		if (x[1] <= 0.7556838095188141) {
			if (x[2] <= 0.06505580805242062) {
				if (x[0] <= 0.005026756087318063) {
					if (x[2] <= 0.004109248286113143) {
						votes[1] += 1;
					}

					else {
						if (x[3] <= 0.0166015625) {
							if (x[2] <= 0.00414550956338644) {
								votes[0] += 1;
							}

							else {
								votes[1] += 1;
							}
						}

						else {
							if (x[1] <= -0.5579502582550049) {
								votes[1] += 1;
							}

							else {
								if (x[1] <= -0.5498014688491821) {
									votes[0] += 1;
								}

								else {
									votes[1] += 1;
								}
							}
						}
					}
				}

				else {
					if (x[0] <= 0.0050319938454777) {
						votes[0] += 1;
					}

					else {
						if (x[0] <= 0.005955884465947747) {
							votes[1] += 1;
						}

						else {
							if (x[0] <= 0.006071638315916061) {
								votes[0] += 1;
							}

							else {
								if (x[2] <= 0.017467142082750797) {
									if (x[2] <= 0.01657207775861025) {
										if (x[1] <= -0.2976943850517273) {
											votes[1] += 1;
										}

										else {
											if (x[1] <= -0.2753622382879257) {
												votes[0] += 1;
											}

											else {
												if (x[2] <= 0.015749970450997353) {
													votes[1] += 1;
												}

												else {
													if (x[2] <= 0.015822197310626507) {
														votes[0] += 1;
													}

													else {
														votes[1] += 1;
													}
												}
											}
										}
									}

									else {
										if (x[1] <= -0.42594216763973236) {
											if (x[3] <= 0.078125) {
												votes[1] += 1;
											}

											else {
												votes[0] += 1;
											}
										}

										else {
											votes[0] += 1;
										}
									}
								}

								else {
									votes[1] += 1;
								}
							}
						}
					}
				}
			}

			else {
				votes[2] += 1;
			}
		}

		else {
			if (x[0] <= 0.011915255337953568) {
				votes[1] += 1;
			}

			else {
				votes[0] += 1;
			}
		}
	}

	else {
		if (x[1] <= 0.5512635111808777) {
			if (x[2] <= 0.05276270769536495) {
				if (x[2] <= 0.039625365287065506) {
					if (x[1] <= 0.24140845239162445) {
						votes[1] += 1;
					}

					else {
						if (x[1] <= 0.48064103722572327) {
							votes[0] += 1;
						}

						else {
							votes[1] += 1;
						}
					}
				}

				else {
					if (x[2] <= 0.05080987513065338) {
						if (x[0] <= 0.02417076099663973) {
							votes[1] += 1;
						}

						else {
							votes[0] += 1;
						}
					}

					else {
						votes[1] += 1;
					}
				}
			}

			else {
				if (x[2] <= 0.06762786209583282) {
					if (x[0] <= 0.07007784396409988) {
						votes[0] += 1;
					}

					else {
						votes[2] += 1;
					}
				}

				else {
					if (x[1] <= 0.41837137937545776) {
						if (x[0] <= 0.6336575150489807) {
							if (x[2] <= 0.11758751422166824) {
								if (x[2] <= 0.11740097403526306) {
									if (x[1] <= 0.12797290459275246) {
										if (x[0] <= 0.07819683849811554) {
											if (x[1] <= -0.3552113026380539) {
												if (x[3] <= 0.375) {
													if (x[2] <= 0.07663864642381668) {
														votes[2] += 1;
													}

													else {
														votes[0] += 1;
													}
												}

												else {
													votes[2] += 1;
												}
											}

											else {
												if (x[1] <= -0.28816722333431244) {
													votes[1] += 1;
												}

												else {
													votes[2] += 1;
												}
											}
										}

										else {
											votes[2] += 1;
										}
									}

									else {
										if (x[3] <= 0.5439453125) {
											votes[2] += 1;
										}

										else {
											if (x[3] <= 0.580078125) {
												votes[0] += 1;
											}

											else {
												if (x[0] <= 0.19322524219751358) {
													votes[2] += 1;
												}

												else {
													votes[0] += 1;
												}
											}
										}
									}
								}

								else {
									votes[0] += 1;
								}
							}

							else {
								if (x[3] <= 0.4951171875) {
									if (x[3] <= 0.4873046875) {
										votes[2] += 1;
									}

									else {
										votes[0] += 1;
									}
								}

								else {
									if (x[2] <= 0.18025855720043182) {
										if (x[2] <= 0.17956680804491043) {
											if (x[0] <= 0.20116082578897476) {
												votes[2] += 1;
											}

											else {
												if (x[2] <= 0.15268460661172867) {
													if (x[0] <= 0.20392189919948578) {
														votes[0] += 1;
													}

													else {
														votes[2] += 1;
													}
												}

												else {
													votes[2] += 1;
												}
											}
										}

										else {
											votes[0] += 1;
										}
									}

									else {
										votes[2] += 1;
									}
								}
							}
						}

						else {
							if (x[2] <= 0.20045693963766098) {
								votes[0] += 1;
							}

							else {
								if (x[0] <= 1.0835275053977966) {
									votes[2] += 1;
								}

								else {
									if (x[3] <= 2.21484375) {
										if (x[1] <= 0.06563227251172066) {
											votes[0] += 1;
										}

										else {
											if (x[3] <= 1.349609375) {
												votes[0] += 1;
											}

											else {
												votes[2] += 1;
											}
										}
									}

									else {
										votes[2] += 1;
									}
								}
							}
						}
					}

					else {
						if (x[2] <= 0.17882797122001648) {
							if (x[0] <= 0.412155345082283) {
								if (x[2] <= 0.1729167178273201) {
									if (x[2] <= 0.08591641113162041) {
										votes[0] += 1;
									}

									else {
										if (x[2] <= 0.12732475623488426) {
											votes[2] += 1;
										}

										else {
											if (x[0] <= 0.25477515161037445) {
												votes[2] += 1;
											}

											else {
												votes[0] += 1;
											}
										}
									}
								}

								else {
									votes[0] += 1;
								}
							}

							else {
								votes[2] += 1;
							}
						}

						else {
							votes[2] += 1;
						}
					}
				}
			}
		}

		else {
			if (x[3] <= 0.681640625) {
				if (x[2] <= 0.09879008308053017) {
					if (x[3] <= 0.4052734375) {
						votes[0] += 1;
					}

					else {
						if (x[1] <= 0.7809997797012329) {
							if (x[2] <= 0.08514923602342606) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							votes[0] += 1;
						}
					}
				}

				else {
					if (x[1] <= 0.834956556558609) {
						if (x[0] <= 0.0689789243042469) {
							votes[0] += 1;
						}

						else {
							votes[2] += 1;
						}
					}

					else {
						votes[0] += 1;
					}
				}
			}

			else {
				if (x[3] <= 0.91796875) {
					if (x[3] <= 0.71875) {
						votes[2] += 1;
					}

					else {
						if (x[2] <= 0.1720867082476616) {
							if (x[3] <= 0.7705078125) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}

						else {
							votes[0] += 1;
						}
					}
				}

				else {
					votes[2] += 1;
				}
			}
		}
	}

	// tree #4
	if (x[0] <= 0.01640331093221903) {
		if (x[0] <= 0.013001636136323214) {
			if (x[0] <= 0.005986940348520875) {
				if (x[3] <= 0.0166015625) {
					if (x[2] <= 0.004106858046725392) {
						if (x[0] <= 0.003524489584378898) {
							votes[1] += 1;
						}

						else {
							if (x[1] <= -0.5824075937271118) {
								if (x[0] <= 0.0035545938881114125) {
									votes[0] += 1;
								}

								else {
									votes[1] += 1;
								}
							}

							else {
								votes[1] += 1;
							}
						}
					}

					else {
						if (x[2] <= 0.00414550956338644) {
							votes[0] += 1;
						}

						else {
							votes[1] += 1;
						}
					}
				}

				else {
					votes[1] += 1;
				}
			}

			else {
				if (x[2] <= 0.007092337356880307) {
					if (x[3] <= 0.0361328125) {
						votes[1] += 1;
					}

					else {
						votes[0] += 1;
					}
				}

				else {
					if (x[1] <= 0.2021588310599327) {
						if (x[3] <= 0.080078125) {
							votes[1] += 1;
						}

						else {
							if (x[3] <= 0.0849609375) {
								votes[0] += 1;
							}

							else {
								votes[1] += 1;
							}
						}
					}

					else {
						if (x[0] <= 0.007210174575448036) {
							votes[0] += 1;
						}

						else {
							votes[1] += 1;
						}
					}
				}
			}
		}

		else {
			if (x[1] <= 0.3010190948843956) {
				votes[1] += 1;
			}

			else {
				votes[0] += 1;
			}
		}
	}

	else {
		if (x[3] <= 0.3681640625) {
			if (x[2] <= 0.016911128535866737) {
				votes[1] += 1;
			}

			else {
				if (x[1] <= 0.21810884773731232) {
					if (x[2] <= 0.05276270769536495) {
						votes[1] += 1;
					}

					else {
						if (x[0] <= 0.06741938367486) {
							if (x[1] <= -0.5999242067337036) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							votes[2] += 1;
						}
					}
				}

				else {
					if (x[0] <= 0.11462144553661346) {
						if (x[0] <= 0.08445674926042557) {
							votes[0] += 1;
						}

						else {
							if (x[1] <= 0.5920173972845078) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}
					}

					else {
						if (x[1] <= 0.8609960079193115) {
							votes[2] += 1;
						}

						else {
							votes[0] += 1;
						}
					}
				}
			}
		}

		else {
			if (x[1] <= 0.7926186621189117) {
				if (x[2] <= 0.16526878625154495) {
					if (x[1] <= 0.4459245651960373) {
						if (x[2] <= 0.16486556828022003) {
							if (x[3] <= 0.6396484375) {
								if (x[0] <= 0.07759395241737366) {
									if (x[1] <= 0.06744109094142914) {
										if (x[0] <= 0.07671055570244789) {
											votes[2] += 1;
										}

										else {
											votes[1] += 1;
										}
									}

									else {
										if (x[0] <= 0.07326551899313927) {
											votes[0] += 1;
										}

										else {
											votes[2] += 1;
										}
									}
								}

								else {
									votes[2] += 1;
								}
							}

							else {
								if (x[1] <= -0.18131182342767715) {
									votes[2] += 1;
								}

								else {
									if (x[3] <= 0.7001953125) {
										if (x[3] <= 0.67578125) {
											votes[0] += 1;
										}

										else {
											if (x[3] <= 0.697265625) {
												if (x[1] <= 0.19522042572498322) {
													votes[0] += 1;
												}

												else {
													votes[2] += 1;
												}
											}

											else {
												votes[0] += 1;
											}
										}
									}

									else {
										votes[2] += 1;
									}
								}
							}
						}

						else {
							votes[0] += 1;
						}
					}

					else {
						if (x[1] <= 0.6358985006809235) {
							if (x[0] <= 0.04439222626388073) {
								votes[2] += 1;
							}

							else {
								if (x[1] <= 0.540113627910614) {
									votes[0] += 1;
								}

								else {
									if (x[3] <= 0.6826171875) {
										if (x[1] <= 0.5554191768169403) {
											votes[2] += 1;
										}

										else {
											votes[0] += 1;
										}
									}

									else {
										votes[2] += 1;
									}
								}
							}
						}

						else {
							votes[2] += 1;
						}
					}
				}

				else {
					if (x[3] <= 2.05078125) {
						if (x[2] <= 0.17708004266023636) {
							if (x[3] <= 1.099609375) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							votes[2] += 1;
						}
					}

					else {
						if (x[3] <= 2.1796875) {
							if (x[1] <= -0.02119797095656395) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							votes[2] += 1;
						}
					}
				}
			}

			else {
				if (x[0] <= 0.44146909564733505) {
					if (x[1] <= 0.8225789070129395) {
						if (x[2] <= 0.08759018778800964) {
							votes[0] += 1;
						}

						else {
							votes[2] += 1;
						}
					}

					else {
						votes[0] += 1;
					}
				}

				else {
					votes[2] += 1;
				}
			}
		}
	}

	// tree #5
	if (x[3] <= 0.369140625) {
		if (x[3] <= 0.0732421875) {
			if (x[1] <= 0.7556838095188141) {
				if (x[3] <= 0.0322265625) {
					if (x[0] <= 0.003524489584378898) {
						votes[1] += 1;
					}

					else {
						if (x[0] <= 0.0035450865980237722) {
							if (x[3] <= 0.017578125) {
								votes[0] += 1;
							}

							else {
								votes[1] += 1;
							}
						}

						else {
							votes[1] += 1;
						}
					}
				}

				else {
					if (x[2] <= 0.007530311355367303) {
						if (x[1] <= -0.5825149416923523) {
							votes[1] += 1;
						}

						else {
							votes[0] += 1;
						}
					}

					else {
						if (x[2] <= 0.015749970450997353) {
							if (x[1] <= 0.13778106123209) {
								votes[1] += 1;
							}

							else {
								if (x[2] <= 0.011637678369879723) {
									if (x[2] <= 0.010831926483660936) {
										votes[1] += 1;
									}

									else {
										votes[0] += 1;
									}
								}

								else {
									votes[1] += 1;
								}
							}
						}

						else {
							if (x[2] <= 0.015780209563672543) {
								votes[0] += 1;
							}

							else {
								votes[1] += 1;
							}
						}
					}
				}
			}

			else {
				if (x[2] <= 0.011621829587966204) {
					votes[1] += 1;
				}

				else {
					votes[0] += 1;
				}
			}
		}

		else {
			if (x[1] <= 0.257094606757164) {
				if (x[0] <= 0.04225102439522743) {
					if (x[2] <= 0.047670384868979454) {
						if (x[3] <= 0.0849609375) {
							if (x[1] <= -0.8561433553695679) {
								if (x[0] <= 0.020265547558665276) {
									votes[0] += 1;
								}

								else {
									votes[1] += 1;
								}
							}

							else {
								votes[1] += 1;
							}
						}

						else {
							votes[1] += 1;
						}
					}

					else {
						votes[0] += 1;
					}
				}

				else {
					if (x[1] <= 0.027281837537884712) {
						if (x[2] <= 0.06168176978826523) {
							votes[2] += 1;
						}

						else {
							if (x[2] <= 0.07056786492466927) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						votes[0] += 1;
					}
				}
			}

			else {
				if (x[0] <= 0.009839488193392754) {
					votes[1] += 1;
				}

				else {
					if (x[0] <= 0.11462144553661346) {
						if (x[1] <= 0.4899807870388031) {
							if (x[2] <= 0.05444801785051823) {
								if (x[1] <= 0.48064103722572327) {
									votes[0] += 1;
								}

								else {
									votes[1] += 1;
								}
							}

							else {
								if (x[0] <= 0.08802925795316696) {
									votes[0] += 1;
								}

								else {
									votes[2] += 1;
								}
							}
						}

						else {
							votes[0] += 1;
						}
					}

					else {
						votes[2] += 1;
					}
				}
			}
		}
	}

	else {
		if (x[1] <= 0.6849452257156372) {
			if (x[1] <= 0.41837137937545776) {
				if (x[0] <= 0.783140629529953) {
					if (x[1] <= -0.23047636449337006) {
						votes[2] += 1;
					}

					else {
						if (x[0] <= 0.32771818339824677) {
							votes[2] += 1;
						}

						else {
							if (x[1] <= -0.2233400046825409) {
								votes[0] += 1;
							}

							else {
								if (x[3] <= 0.892578125) {
									if (x[0] <= 0.5106902420520782) {
										if (x[0] <= 0.3318428695201874) {
											votes[0] += 1;
										}

										else {
											votes[2] += 1;
										}
									}

									else {
										if (x[1] <= 0.24575969576835632) {
											votes[0] += 1;
										}

										else {
											votes[2] += 1;
										}
									}
								}

								else {
									votes[2] += 1;
								}
							}
						}
					}
				}

				else {
					if (x[2] <= 0.2628515139222145) {
						if (x[2] <= 0.20188118517398834) {
							votes[0] += 1;
						}

						else {
							if (x[1] <= 0.19373300671577454) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}
					}

					else {
						if (x[3] <= 2.2822265625) {
							if (x[2] <= 0.4468701332807541) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}

						else {
							votes[2] += 1;
						}
					}
				}
			}

			else {
				if (x[0] <= 0.12239959836006165) {
					if (x[1] <= 0.6358985006809235) {
						if (x[2] <= 0.0959102138876915) {
							votes[0] += 1;
						}

						else {
							if (x[0] <= 0.10130305215716362) {
								votes[2] += 1;
							}

							else {
								votes[0] += 1;
							}
						}
					}

					else {
						votes[2] += 1;
					}
				}

				else {
					if (x[2] <= 0.155110664665699) {
						if (x[3] <= 0.7509765625) {
							votes[2] += 1;
						}

						else {
							votes[0] += 1;
						}
					}

					else {
						if (x[1] <= 0.537114828824997) {
							votes[2] += 1;
						}

						else {
							if (x[0] <= 0.5021569728851318) {
								votes[2] += 1;
							}

							else {
								if (x[2] <= 0.39256350696086884) {
									votes[0] += 1;
								}

								else {
									votes[2] += 1;
								}
							}
						}
					}
				}
			}
		}

		else {
			if (x[1] <= 0.8225789070129395) {
				if (x[1] <= 0.813092440366745) {
					if (x[2] <= 0.29655127227306366) {
						if (x[0] <= 0.06296985596418381) {
							if (x[2] <= 0.0799485594034195) {
								votes[0] += 1;
							}

							else {
								votes[2] += 1;
							}
						}

						else {
							if (x[3] <= 0.5) {
								votes[0] += 1;
							}

							else {
								if (x[2] <= 0.16825038939714432) {
									votes[2] += 1;
								}

								else {
									votes[0] += 1;
								}
							}
						}
					}

					else {
						votes[2] += 1;
					}
				}

				else {
					votes[2] += 1;
				}
			}

			else {
				if (x[0] <= 0.04122284613549709) {
					votes[2] += 1;
				}

				else {
					votes[0] += 1;
				}
			}
		}
	}

	// return argmax of votes
	uint8_t classIdx = 0;
	float maxVotes = votes[0];

	for (uint8_t i = 1; i < 3; i++) {
		if (votes[i] > maxVotes) {
			classIdx = i;
			maxVotes = votes[i];
		}
	}

	*prob = get_prob(votes, classIdx);
	return classIdx;
}

/**
* Predict readable class name
*/
const char* predictLabel(float *x, float *prob) {
	return idxToLabel(predict(x, prob));
}

/**
* Convert class idx to readable name
*/
const char* idxToLabel(uint8_t classIdx) {
	switch (classIdx) {
		case 0:
		return "flying";
		case 1:
		return "low_activity";
		case 2:
		return "feeding";
		default:
		return "Houston we have a problem";
	}
}
